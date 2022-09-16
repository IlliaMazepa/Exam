#include "Iron.h"

Iron::Iron()
{
    cost = 2000;
    perMonthPrice = 500;
    insur = false;
    car = false;
}

Iron::Iron(string name_, float money_, bool holder_, string producer_, bool car_)
:Platinum(name_,  money_, holder_, producer_)
{
    car = car_;
}

Iron::~Iron()
{
}


void Iron::setCar(bool car_)
{
    car = car_;
}


bool Iron::getCar() const
{
    return car;
}

string Iron::type() const
{
    return "Iron";
}

void Iron::show() const
{
    Platinum::show();
}

void Iron::showDetails() const
{
    Platinum::showDetails();
    if (car) {
        if (insur) {
            cout << "\nInsurance is active\n";
        }
        else {
            cout << "\nInsurance is not active\n";
        }

    }
}


void Iron::Insurance()
{
    if (car) {
        int m;
        cout << "Choose category: \n";
        cout << "1.Econom - 1000\n";
        cout << "2.Standart - 1500\n";
        cout << "3.Premiom - 2000\n";
        cin >> m;
        if (m == 1)WithDraw(1000);
        else if (m == 2)WithDraw(1500);
        else if (m == 3)WithDraw(2000);
    }
}

string Iron::toString() const
{
    return string();
}
