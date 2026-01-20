#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked,
            this, &MainWindow::onLoginClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);
    connect(ui->bay, &QPushButton::clicked, this , &MainWindow::onBayClicked);
    connect(ui->sell, &QPushButton::clicked, this , &MainWindow::onSellClicked);
    connect(ui->backto, &QPushButton::clicked, this , &MainWindow::onBacktoClicked);
    connect(ui->balanButton, &QPushButton::clicked,this, &MainWindow::onBalanClicked);
    connect(ui->balanceButton, &QPushButton::clicked, this, &MainWindow::onBalanceClicked);
    connect(ui->depozitButton, &QPushButton::clicked, this, &MainWindow::onDepozitClicked);
    connect(ui->deposButton, &QPushButton::clicked,this, &MainWindow::onDeposClicked);
    connect(ui->moneyButton, &QPushButton::clicked,this, &MainWindow::onMoneyClicked);
    connect(ui->withdrawButton, &QPushButton::clicked, this, &MainWindow::onWithdrawClicked);
    connect(ui->minusbackButton, &QPushButton::clicked,this, &MainWindow::onMinusbackClicked);
    connect(ui->cfdButton, &QPushButton::clicked,this, &MainWindow::onCfdClicked);
    connect(ui->minusButton, &QPushButton::clicked,this, &MainWindow::onMinusClicked);

    ui->pinEdit_2->setValidator(new QIntValidator(0, 9999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    QString card = ui->cardEdit_2->text().trimmed();
    QString pinText = ui->pinEdit_2->text().trimmed();

    if (card.isEmpty()) {
        QMessageBox::warning(this, "Login", "Enter card number");
        return;
    }

    if (pinText.isEmpty()) {
        QMessageBox::warning(this, "Login", "Enter PIN");
        return;
    }

    bool ok = false;
    int pin = pinText.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Login", "PIN must be a number");
        return;
    }

    qDebug() << "CARD:" << card;
    qDebug() << "PIN:" << pin;

    if (bank.login(card, pin)) {
        double balance = bank.getBalance();
          ui->balanceLabel->setText("Balance: €" + QString::number(balance, 'f', 2));
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    }


    else{
        QMessageBox::warning(this, "Login", "incorrect data");
    }

}
void MainWindow::onLogoutClicked(){
    qDebug()<<"click";
    ui->stackedWidget->setCurrentWidget(ui->page_0);

    ui->cardEdit_2->clear();
    ui->pinEdit_2->clear();
}
void MainWindow::onBalanceClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void MainWindow::onBalanClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow::onDepozitClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}
void MainWindow::onDeposClicked(){
    qDebug() << "caled depos";
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void MainWindow::onMinusbackClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void MainWindow::onMoneyClicked(){
  QString text = ui->sum->text().trimmed();

    if (text.isEmpty()){
      QMessageBox::warning(this, "Emty ", "add deposit");
        return;
    }

    bool ok;
    double amout = text.toDouble(&ok);

    if (!ok || amout<= 0){
        QMessageBox::warning(this, "Depozit", "invalid sintax");
    }

    bank.depozit(amout);
    double balance = bank.getBalance();

      ui->balanceLabel->setText("Balance: €" + QString::number(balance, 'f', 2));
    if (amout){
          QMessageBox::information(this, "your " , "money is add" );

    }
    ui->sum->clear();


}
void MainWindow::onWithdrawClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_5);
}
void MainWindow::onMinusClicked(){
    QString text = ui->minussum->text().trimmed();
    if (text.isEmpty()){
        QMessageBox::warning(this, "Emty ", "add withdraw");
        return;
    }
    bool ok;
    double amout = text.toDouble(&ok);

    if (!ok || amout <=0){
        QMessageBox::warning(this, "Withdraw", "is invalid sintax");
            return;
    }
    if (!bank.withdraw(amout)) {
        QMessageBox::warning(this, "Withdraw", "Not enough balance");
        return;
    }

    double balance = bank.getBalance();
    ui->balanceLabel->setText("Balance: €" + QString::number(balance, 'f', 2));
      QMessageBox::warning(this, "your  ", " money is take out");
    ui->minussum->clear();

}
void MainWindow::onBacktoClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::onBayClicked(){
     QMessageBox::information(this, "","bay");
}
void MainWindow::onSellClicked(){
    QMessageBox::information(this, "","sell");
}
void MainWindow::onCfdClicked(){
    ui->stackedWidget->setCurrentWidget(ui->page_6);
}
