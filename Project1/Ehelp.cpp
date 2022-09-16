#include "Ehelp.h"

Ehelp::Ehelp()
{
}

Ehelp::Ehelp(string name_, float money_)
	:Card(name_, money_)
{
}

Ehelp::~Ehelp()
{
}

void Ehelp::Donate()
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

string Ehelp::type() const
{
    return "EHelp";
}

void Ehelp::show() const
{
    Card::show();
}

void Ehelp::showDetails() const
{
    Card::show();
}

void Ehelp::OpenC()
{
}

void Ehelp::OpenD()
{
}

void Ehelp::CloseC()
{
}

void Ehelp::CloseD()
{
}

void Ehelp::CashBack()
{
}

void Ehelp::Insurance()
{
}

string Ehelp::toString() const
{
    return string();
}
