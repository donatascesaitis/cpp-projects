#include "BankBrain.h"
using namespace std;


bool BankBrain::login(const QString& card, int pin){

    if(card == "555666555" && pin == 1234){

        balance = 1000.0;
        return true;
    }
    return false;
}


void BankBrain::depozit(double amount){
    if(amount > 0)
    balance += amount;

}


bool BankBrain::withdraw(double amount){
    if(amount <= 0 || amount > balance)
    return false;

    balance -= amount;
    return true;
}

double BankBrain::getBalance() const{
    return balance;
}
