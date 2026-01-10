#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <string>

namespace fs = std::filesystem;
using namespace std;


bool check_file(const string& filepath, const string& logFile) {
  
    string cmd = "g++ -fsyntax-only \"" + filepath + "\" -o temp.exe 2> \"" + logFile + "\"";
    int ret = system(cmd.c_str());

    return ret == 0; 
}


void read_log(const string& logFile) {
    ifstream file(logFile);
    if (!file) {
        cerr << "Cannot open log file " << logFile << endl;
        return;
    }

    string line;
    bool hasErrors = false;

    while (getline(file, line)) {
     
        size_t pos1 = line.find(":");
        if (pos1 != string::npos) {
            size_t pos2 = line.find(":", pos1 + 1);
            if (pos2 != string::npos) {
                string fileLine = line.substr(pos1 + 1, pos2 - pos1 - 1);

                if (line.find("error:") != string::npos) {
                    cerr << "Error on line " << fileLine << ": " << line << endl;
                    hasErrors = true;
                    continue;
                } else if (line.find("warning:") != string::npos) {
                    clog << "Warning on line " << fileLine << ": " << line << endl;
                    continue;
                }
            }
        }

        cout << line << endl;
    }

    if (hasErrors) {
        cout << "There were errors in compilation.\n";
    } else {
        cout << "No compilation errors.\n";
    }
}

int main() {
    string srcPath = "C:\\Users\\donat\\Desktop\\system-motor\\src"; 
    string logFile = "compile_errors.log";

    cout << "System Motor Analyzer started" << endl;

    for (auto& entry : fs::directory_iterator(srcPath)) {
        if (entry.path().extension() == ".cpp") {
            cout << "\nChecking file: " << entry.path().filename() << endl;

            bool ok = check_file(entry.path().string(), logFile);
            read_log(logFile);

            if (ok) {
                cout << "File compiles without errors.\n";
            } else {
                cout << "File has errors.\n";
            }
        }
    }

    return 0;
}
