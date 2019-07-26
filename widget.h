#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    void canIclick();
    void returnMoney();
    void reset();
    int money{0};
    int money_500{0};
    int money_100{0};
    int money_50{0};
    int money_10{0};
    int coffeeNum{0};
    int teaNum{0};
    int beerNum{0};
    int drinkTmp{0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbBeer_clicked();

    void on_pbBackMoney_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
