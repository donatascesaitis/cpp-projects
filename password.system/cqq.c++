#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>
#include <string>
#include <conio.h>
using namespace std;
string inputWeebPassword();
namespace fs = filesystem;

int ch;
int passwordFILE;
int menu;
int fileID = 1;
string answer;
string toSearch;
string weebname, weebpassword;
string fileweeb;






void exiit(){
   while (true){
    cout << "do you wont exit? yes/no";
    cin >> answer;
    if (answer == "yes"){
        cout << " goodbye program is clousing";
        exit(0);
    }
    if (answer == "no")
    return;
   }
}

bool onlineweebExist(const string& weebname, const string& weebpassword){
      if (!fs::exists("passwordFILE")) return false;
      for (const auto& dir : fs::directory_iterator("passwordFILE")){
        if (!dir.is_directory()) continue;
        ifstream file(dir.path() / "filpassword.txt");
        if (!file) continue;
        string line;
        string fileweebname, fileweebpassword;
        while (getline (file, line)){
            if (line.rfind("weebname: ", 0) == 0)
            fileweebname = line.substr(10);
            if (line.rfind("weebpassword: ", 0) == 0)
            fileweebpassword = line.substr(14);
            
        }
        if (fileweebname == weebname && fileweebpassword == weebpassword){
            return true;
        }
    
    }
    return false;
}


void onlineweebpassword(){
    cout << "enter your website and password" << endl;
    cout << " enter  website" ;
    getline(cin, weebname);

    cout << "enter  password" << endl;
    getline(cin, weebpassword);
    if (onlineweebExist(weebname, weebpassword)){
        cout << "dis online file and password already saved" << endl;
        return;
    }

    else{
         cout << "There is no such your info in the system: "<< endl;
         cout << "If you want to enter an your  into the system, press 1: ";
    }    
}

void addonlinePWS(){
    cout << "enter your online" << endl;
    getline(cin, weebname);
    cout << "enter your password ";
     weebpassword = inputWeebPassword();

   if(onlineweebExist(weebname, weebpassword)){
    cout << " dis file and password already saved!\n";
    cout << "----------------------------------------------------------------------------------------------------------------------";
    return;
 }
  string folder = "passwordFILE/" + to_string(fileID);
     fs::create_directories(folder);

     ofstream file(folder + "/filpassword.txt");

    file << "ID" << fileID<< "\n";
    file << "weebname: " << weebname << "\n";
    file << "weebpassword: " << weebpassword << "\n";
    file.close(); 
    fileID++;
    cout << "file data saved successfully.\n";
    cout << " ";
     return;
}

void checkweebpassword(){
            string toSearch;
            cout << "Enter the desired website whose password you want to find.: " << endl;
            cout << "enter webside:" << endl;
            string line;
            getline(cin, toSearch);


            if(!fs::exists("passwordFILE")){
                cout << "Password storage not found.\n";
                return;
            }
               for (const auto& dir : fs::directory_iterator("passwordFILE")){
        if (!dir.is_directory()) continue;
        ifstream file(dir.path() / "filpassword.txt");
        if (!file) continue;
        string line;
        string fileweebname, fileweebpassword;
        while (getline (file, line)){
            if (line.rfind("weebname: ", 0) == 0)
            fileweebname = line.substr(10);
            if (line.rfind("weebpassword: ", 0) == 0)
            fileweebpassword = line.substr(14);
            
        }     
        if (fileweebname== toSearch){
            cout << "Website: " <<fileweebname<< endl;
            cout << "Password: " << fileweebpassword << endl;
            return;
        }           
}
}
string inputWeebPassword(){
    string weebpassword;
    char ch;
    while (true)
    {
     ch = getch();
     if (ch == 13){
        cout << endl;
        break;
    }
    else if (ch == 8) { // Backspace
            if (!weebpassword.empty()) {
                weebpassword.pop_back();
                cout << "\b \b";
            }
        }
        else {
            weebpassword.push_back(ch);
            cout << "*";
        }
    }
    return weebpassword;
}


int main(){
     fs::create_directories("passwordFILE");
 while (true)
 {
    cout << "menu password files pres 1 check your online o exsist , 2 add online and passwprd" << endl;
    cout << "press 0 to exit";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (menu)
    {
    case 0:exiit();break;
    case 1:onlineweebpassword();break;
    case 2:addonlinePWS();break;
    case 3:checkweebpassword();break;
    }
    
}
 
    
    
    
}



