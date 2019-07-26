#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbBeer->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    if(n < 0) drinkTmp = 1;
}

void Widget::canIclick(){
    if(money < 50){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbBeer->setEnabled(false);
    }
    else if(money < 100){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbBeer->setEnabled(false);
    }
    else if(money < 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbBeer->setEnabled(false);
    }
    else{
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbBeer->setEnabled(true);
    }
}

void Widget::returnMoney(){
    while(money >= 500){
        money_500 += 1;
        money -= 500;
    }
    while(money >= 100){
        money_100 += 1;
        money -= 100;
    }
    while(money >= 50){
        money_50 += 1;
        money -= 50;
    }
    while(money > 0){
        money_10 += 1;
        money -= 10;
    }
}

void Widget::reset(){
    money_500 = 0;
    money_100 = 0;
    money_50 = 0;
    money_10 = 0;
    coffeeNum = 0;
    teaNum = 0;
    beerNum = 0;
    drinkTmp = 0;
    ui->lcdNumber->display(QString::number(money));
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbBeer->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    canIclick();
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    canIclick();
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    canIclick();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    canIclick();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-50);
    canIclick();
    coffeeNum += 1;
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-100);
    canIclick();
    teaNum += 1;
}

void Widget::on_pbBeer_clicked()
{
    changeMoney(-200);
    canIclick();
    beerNum += 1;
}

void Widget::on_pbBackMoney_clicked()
{
    if(money > 0 && drinkTmp){
        returnMoney();
        QMessageBox msg;
        msg.information(nullptr, "알림", "coffee : "+QString::number(coffeeNum)+"개"+"tea : "+QString::number(teaNum)+"개"+"beer : "+QString::number(beerNum)+"개"+"500원 짜리 "+QString::number(money_500)+"개, \n"+"100원 짜리 "+QString::number(money_100)+"개, "+"50원 짜리 "+QString::number(money_50)+"개, "+"10원 짜리 "+QString::number(money_10)+"개 반환");
    }
    else if(money == 0 && drinkTmp){
        QMessageBox msg;
        msg.information(nullptr, "알림", "coffee : "+QString::number(coffeeNum)+"개"+"tea : "+QString::number(teaNum)+"개"+"beer : "+QString::number(beerNum)+"개 반환");
    }
    else if(money > 0 && !drinkTmp){
        returnMoney();
        QMessageBox msg;
        msg.information(nullptr, "알림", "500원 짜리 "+QString::number(money_500)+"개, "+"100원 짜리 "+QString::number(money_100)+"개, "+"50원 짜리 "+QString::number(money_50)+"개, "+"10원 짜리 "+QString::number(money_10)+"개 반환");
    }
    else{
        QMessageBox msg;
        msg.information(nullptr, "알림", "NO RETURN");
    }
    reset();
}
