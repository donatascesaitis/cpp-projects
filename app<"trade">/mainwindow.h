#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BankBrain.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onLogoutClicked();
    void onBalanceClicked();
    void onBalanClicked();
    void onDepozitClicked();
    void onDeposClicked();
    void onMoneyClicked();
    void onWithdrawClicked();
    void onMinusbackClicked();
    void onMinusClicked();
    void onBayClicked();
    void onSellClicked();
    void onBacktoClicked();
    void onCfdClicked();


private:
    Ui::MainWindow *ui;
    BankBrain bank;
};

#endif
