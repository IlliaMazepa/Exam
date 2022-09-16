#include "Platinum.h"

Platinum::Platinum()
{
    cost = 500;
    perMonthPrice = 99.99;
}

Platinum::Platinum(string name_, float money_, bool holder_, string producer_)
    :Black(name_,money_,holder_,producer_)
{
}

Platinum::~Platinum()
{
}

void Platinum::setCost(float cost_)
{
    cost = cost_;
}

void Platinum::setPrice(float perMonthPrice_)
{
    perMonthPrice = perMonthPrice_;
}

float Platinum::getCost() const
{
    return cost;
}

float Platinum::getPrice() const
{
    return perMonthPrice;
}

string Platinum::type() const
{
    return "Platinum";
}

void Platinum::show() const
{
    Black::show();
}

void Platinum::showDetails() const
{
    show();
    cout << "New " << type() << " card cost " << cost << " $\n";
    cout<<"Price per month: "<<perMonthPrice << " $\n";
    cout << "Cashback: ";
    if (cashBack == 0)cout << "off";
    else if (cashBack == 2)cout << "Products 2%";
    else if (cashBack == 1.5)cout << "Drugs 1.5%";
    else if (cashBack == 1.7)cout << "Gas stations 1.7%";
    else if (cashBack == 4)cout << "Miles 4%";
}

void Platinum::CashBack()
{
    int m;
    cout << "Choose category: \n";
    cout << "1.Products\n";
    cout << "2.Drugs\n";
    cout << "3.Gas stations\n";
    cout << "4.Miles\n";
    cin >> m;
    if (m == 1)cashBack = 2;
    else if (m == 2)cashBack = 1.5;
    else if (m == 3)cashBack = 1.7;
    else if (m == 4)cashBack = 4;
}

void Platinum::Insurance()
{
    cout << "Platinum";
}

string Platinum::toString() const
{
    return string();
}
