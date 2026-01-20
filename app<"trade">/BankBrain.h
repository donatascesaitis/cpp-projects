#include <iostream>
#include <string>
#include <QString>
#pragma once
using namespace std;



class BankBrain{
public:
bool login(const QString& card, int pin);

void depozit(double amount);
bool withdraw(double amount);

double getBalance()const;

  private:
  string currentCard;
  double balance = 0.0;


};

