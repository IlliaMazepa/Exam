#include "Dollar.h"

Dollar::Dollar()
{
    ExchangeRate = 40;
}

void Dollar::setEx(double Rate)
{
    ExchangeRate = Rate;

}

double Dollar::getEx() const
{
    return ExchangeRate;
}

void Dollar::TopUp(double a)
{
    money += a / ExchangeRate;
}

void Dollar::WithDraw(double a)
{
    money -= a / ExchangeRate;
}

string Dollar::type() const
{
    return "Dollar";
}

void Dollar::show() const
{
    Card::show();
}

void Dollar::showDetails() const
{
    Card::show();
    cout << "Exchange rate today: " << ExchangeRate << endl;
}

void Dollar::Donate()
{
}

void Dollar::OpenC()
{
}

void Dollar::OpenD()
{
}

void Dollar::CloseC()
{
}

void Dollar::CloseD()
{
}

void Dollar::CashBack()
{
}

void Dollar::Insurance()
{
}


string Dollar::toString() const
{
    return string();
}

Dollar::Dollar(string name_, float money_)
    :Card(name_, money_)
{
}

Dollar::~Dollar()
{
}
