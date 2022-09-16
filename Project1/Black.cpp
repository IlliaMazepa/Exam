#include "Black.h"

Black::Black()
{
    holder = false;
    producer = "M";
    cashBack = 0;
}

Black::Black(string name_, float money_, bool holder_, string producer_)
    :Card(name_,money_)
{
    holder = holder_;
    producer = producer_;
}

Black::~Black()
{
}

void Black::setHolder(bool holder_)
{
    holder = holder_;
}

void Black::setProducer(string producer_)
{
    producer = producer_;
}

bool Black::getHolder() const
{
    return holder;
}

string Black::getProducer() const
{
    return producer;
}

string Black::type() const
{
    return "Black";
}

void Black::show() const
{
    Card::show();
    if (holder)cout << name << endl;
    if (producer == "M")cout << "MASTER CARD";
    else if(producer == "V")cout<<"VISA";
}

void Black::showDetails() const
{
    show();
    cout << "Cashback: ";
    if (cashBack == 0)cout << "off";
    else if (cashBack == 2)cout << "Products 2%";
    else if (cashBack == 1.5)cout << "Drugs 1.5%";
    else if (cashBack == 1.7)cout << "Gas stations 1.7%";
}

void Black::Donate()
{
    int m;
    cout << "Choose organization: \n";
    cout << "1.Back home alive\n";
    cout << "2.UNITED24\n";
    cout << "3.Sergiy Prytula\n";
    cin >> m;
    WithDraw();
    cout << "TOGETHER WE ARE STRONGER!!!GLORY TO UKRAINE\n";
}

void Black::CashBack()
{
    int m;
    cout << "Choose category: \n";
    cout << "1.Products\n";
    cout << "2.Drugs\n";
    cout << "3.Gas stations\n";
    cin >> m;
    if (m == 1)cashBack = 2;
    else if (m == 2)cashBack = 1.5;
    else if (m == 3)cashBack = 1.7;
}

void Black::OpenC()
{
}

void Black::OpenD()
{
}

void Black::CloseC()
{
}

void Black::CloseD()
{
}

void Black::Insurance()
{
    cout << "Black";
}

string Black::toString() const
{
    return string();
}
