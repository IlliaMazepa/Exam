#include "Euro.h"

Euro::Euro()
{
	ExchangeRate = 41;
}

Euro::Euro(string name_, float money_)
	:Card(name_, money_)
{
}

Euro::~Euro()
{
}

void Euro::setEx(double Rate)
{
    ExchangeRate = Rate;

}

double Euro::getEx() const
{
    return ExchangeRate;
}

void Euro::TopUp(double a)
{
    money += a / ExchangeRate;
}

void Euro::WithDraw(double a)
{
    money -= a / ExchangeRate;
}

string Euro::type() const
{
    return "Euro";
}

void Euro::show() const
{
    Card::show();
}

void Euro::showDetails() const
{
    Card::show();
    cout << "Exchange rate today: " << ExchangeRate << endl;
}

void Euro::Donate()
{
}

void Euro::OpenC()
{
}

void Euro::OpenD()
{
}

void Euro::CloseC()
{
}

void Euro::CloseD()
{
}

void Euro::CashBack()
{
}

void Euro::Insurance()
{
}

string Euro::toString() const
{
    return string();
}
