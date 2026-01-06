# include<iostream>
# include<conio.h>
# include<string>
#include <fstream>

float take, įnašas, sum;
using namespace std;
int card;
int menu;
int balance1 =  0;
int choise;
int attempts;


void card1(){
    int ch;
    string cardd, password;
    cout << "enter your card :" << endl;
    cout << "-----------------------------" << endl;
    cin >> cardd;
      
  while (true){
    if (cardd == "LT-555-44-88-99"){
        cout << "  " << endl;
        cout << "card found" << endl; 
        cout << "-----------------------------" << endl;
        cout << "enter your password :" << endl;
        break;
    }
    else{
        cout << "card not found, please enter again" << endl;
        cout << "-----------------------------" << endl;
        cout << "enter your card :" << endl;
        cout << " " << endl;
        cin >> cardd;
    }
  }
    while (true){
    ch = getch();

    if (ch == 13){
        break;
    }
       password.push_back(ch);
       cout<< "*";
  }


     cout << endl;
     attempts = 0;
  while (true){
  if (password == "5559"){
    cout << endl;
    cout << "password is correct" << endl; 
    cout << " " << endl;
    cout << " [--------- SELECTION MENU ---------] " << endl;
    cout << " " << endl;
    cout << "[ 1--CHECK BALANCE ] " << " | " << "[ 2-- DEPOSIT MONEY ]" << " | " <<  " [ 3-- [WITHDRAW MONEY ]" << " | " << "[4--EXIT ]" << endl;
    cin >> menu;
    break;

    }
    else{
         attempts++;
     cout << endl;
       if (attempts == 3){
            cout << "-----------------------------" << endl;
            cout << " your card is blocked :" << endl;
            cout << "contacts with your bank :" << endl; 
            break;
         }
     cout << "-----------------------------" << endl;
     cout << "incorrect password" << endl;
     cout << "try again" << endl;
     cout << "-----------------------------" << endl;
     cout << "enter your password :" << endl;
    password.clear();
    }
    while (true){
           ch = getch();

    if (ch == 13){
        break;
    }   
       password.push_back(ch);
       cout << "*" ;
    }
  }
}

     
void balance(){
      ifstream file("balance.txt");
      if( file.is_open()){
      file >> balance1;
      file.close();
        }
     

      cout << "you have " << " "<< balance1 << " " << "eur" << endl;
      cout << " " << endl;
      cout << "[ 1--CHECK BALANCE ] " << " | " << "[ 2-- DEPOSIT MONEY ]" << " | " <<  " [ 3-- [WITHDRAW MONEY ]" << " | " << "[4--EXIT ]" << endl;
      cin >> menu;
}


void addmoney(){
  cout << "how much do you want to deposit";
  cin >> įnašas;
  sum = balance1 + įnašas ;

     cout << "you add money  : " << "sum " << įnašas << " " << "eur" << endl;
     cout << " " << endl;
     cout << "[ 1--CHECK BALANCE ] " << " | " << "[ 2-- DEPOSIT MONEY ]" << " | " <<  " [ 3-- [WITHDRAW MONEY ]" << " | " << "[4--EXIT ]" << endl;

     ofstream file( "balance.txt");
      file << sum;
      file.close();
      balance1 = sum;

     cin >> menu;
}



void takemoney(){
      cout << "  ";
      cout << "how how much money do you want to take: " << endl;
      cin >> take;
      sum = balance1 - take;

      cout << "you take out:" << " " << "sum " << take << " " << endl;
      cout << " " << endl;
      cout << "[ 1--CHECK BALANCE ] " << " | " << "[ 2-- DEPOSIT MONEY ]" << " | " <<  " [ 3-- [WITHDRAW MONEY ]" << " | " << "[4--EXIT ]" << endl;
     
      ofstream file("balance.txt");
      file  << sum;
      file.close();
      balance1 = sum; 

      cin >> menu;

}

void exit(){
  cout << "Thank you for using SEB Bank :" << endl;
  cout << "Have a good day : " << endl;
}
int main(){
        cout << "add the card pres 0" << endl;
        cin >> card;
        switch (card)
        {
        case 0:card1();
            break;
         }
         while (true)
         {
              
         switch (menu){
         case 1:balance();break;
         case 2:addmoney();break;
         case 3:takemoney();break;
         case 4:exit();return 0;
         
         }
    }

}
