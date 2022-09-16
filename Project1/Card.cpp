#include "Card.h"

Card::Card()
{
    name = "";
    number="";
    money = 0;
    pin = "";
}

Card::Card(string name_, float money_)
{
    srand(time(NULL));
    name = name_;
    for (int i = 0;i < 16;i++) {
        number += rand() % (58 - 48) + 48;
    }
    money = money_;
    for (int i = 0;i < 4;i++) {
        pin += rand() % (58 - 48) + 48;
    }
}

Card::~Card()
{
}

void Card::setName(string name_)
{
    name = name_;
}

void Card::setNumber(string number_)
{
    number = number_;
}

void Card::setMoney(float money_)
{
    money = money_;
}

void Card::setPin(string pin_)
{
    pin = pin_;
}

string Card::getName() const
{
    return name;
}

string Card::getNumber() const
{
    return number;
}

float Card::getMoney() const
{
    return money;
}

string Card::getPin() const
{
    return pin;
}

void Card::Change_PIN()
{
    string nP;
    cout << "Enter new PIN: ";
    cin >> nP;
    if(nP.size()>4)throw "Wrong pin";
    for (int i = 0;i < nP.size();i++) {
        if(nP[i]<48&&nP[i]>57)throw "Wrong pin";
    }
    setPin(nP);
    
}

void Card::TopUp()
{
    float n;
    cout << "Enter sum: ";cin >> n;
    
    try {
        if (n < 5)throw(n);
        money += n;
    }
    catch(float sum){
        cout << "Wrong sum";
    }
}

void Card::TopUp(float a)
{
    if (a < 5)throw(a);
    try {
        money += a;
    }
    catch (float sum) {
        cout << "Wrong sum";
    }
}

void Card::WithDraw()
{
    float n;
    cout << "Enter sum: ";cin >> n;
    if (money < n)throw (n);
    try {
        money -= n;
    }
    catch (float sum) {
        cout << "Wrong sum";
    }
}

void Card::WithDraw(float a)
{
    if (money < a)throw (a);
    try {
        money -= a;
    }
    catch (float sum) {
        cout << "Wrong sum";
    }
}



void Card::show() const
{
    cout << "Card: " << type() << endl;
    cout << "\nCard number: ";
    for (int i = 0;i < number.size();i++) {
        cout << number[i];
        if (i == 3 || i == 7 || i == 11)cout << " ";
    }
    cout << "\nMoney: " << money << " $\n";
    cout << "PIN: " << pin << endl;
}


