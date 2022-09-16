#include "White.h"

White::White()
{
    percentC = 0;
    percentD = 0;
    Credit = false;
    Deposit = false;
    termC = 0;
    termD = 0;
    debt = 0;
    dep = 0;
    producer = "M";
}

White::White(string name_, float money_, string producer_)
    :Card(name_, money_)
{
    Credit = false;
    Deposit = false;
    producer = producer_;
}

White::~White()
{
}

void White::setPrecentC(float percentC_)
{
    percentC = percentC_;
}

void White::setPrecentD(float percentD_)
{
    percentD = percentD_;
}

void White::setC(bool Credit_)
{
    Credit = Credit_;
}

void White::setD(bool Deposit_)
{
    Deposit = Deposit_;
}

void White::setTermC(int termC_)
{
    termC = termC_;
}

void White::setTermD(int termD_)
{
    termD = termD_;
}

void White::setDebt(double debt_)
{
    debt = debt_;
}

void White::setDep(double dep_)
{
    dep = dep_;
}

void White::setProducer(string producer_)
{
    producer = producer_;
}

float White::getPercentC() const
{
    return percentC;
}

float White::getPercentD() const
{
    return percentD;
}

bool White::getC() const
{
    return Credit;
}

bool White::getD() const
{
    return Deposit;
}

int White::getTermC() const
{
    return termC;
}

int White::getTermD() const
{
    return termD;
}

double White::getDebt() const
{
    return debt;
}

double White::getDep() const
{
    return dep;
}

string White::getProducer() const
{
    return producer;
}

void White::CashBack()
{
}

void White::Insurance()
{
}

void White::Donate()
{
}

void White::OpenC()
{
    if (Credit == false) {
        int m;
        double a;
        cout << "Choose your creditplan: \n";
        cout << "1. One year - 10%\n";
        cout << "2. Two years - 12%\n";
        cout << "3. Five years - 17.5\n";
        cin >> m;
        if (m == 1) {
            cout << "Enter sum: ";cin >> a;
            
            TopUp(a);
           
            termC = 1;
            percentC = 10;
            debt = a + a * (percentC/100*termC);
            Credit = true;
            cout << "\nYour credit has been opened succesfuly\n";
        }
        else if (m == 2) {
            cout << "Enter sum: ";cin >> a;
            
            TopUp(a);
            termC = 2;
            percentC = 12;
            debt = a + a * (percentC / 100 * termC);
            Credit = true;
            cout << "\nYour credit has been opened succesfuly\n";
        }
        else if (m == 3) {
            cout << "Enter sum: ";cin >> a;
            
            TopUp(a);
            termC = 5;
            percentC = 17.5;
            debt = a + (a * percentC / 100) * termC;
            Credit = true;
            cout << "\nYour credit has been opened succesfuly\n";
        }
    }

    else {
        cout << "You also has credit \t Your debt is " << debt << "\tPercent: " << percentC << "%\tTerm is " << termC << endl;

    }
}

void White::OpenD()
{
    if (Deposit == false) {
        int m;
        double a;
        cout << "Choose your depositplan: \n";
        cout << "1. One year - 8%\n";
        cout << "2. Two years - 10%\n";
        cout << "3. Five years - 15.5\n";
        cin >> m;
        if (m == 1) {
            cout << "Enter sum: ";cin >> a;
            WithDraw(a);
            dep = a;
           
            termD = 1;
            percentD = 8;
            Deposit = true;
            cout << "\nYour deposit has been opened succesfuly\n";
        }
        else if (m == 2) {
            cout << "Enter sum: ";cin >> a;
            WithDraw(a);
            dep = a;
            
            termD = 2;
            percentD = 10;
            Deposit = true;
            cout << "\nYour Deposit has been opened succesfuly\n";
        }
        else if (m == 3) {
            cout << "Enter sum: ";cin >> a;
            WithDraw(a);
            dep = a;
            
            termD = 5;
            percentD = 15.5;
            Deposit = true;
            cout << "\nYour Deposit has been opened succesfuly\n";
        }
    }

    else {
        cout << "You also has deposit \t Your deposit is " << dep << "\tPercent: " << percentD << "%\tTerm is " << termD << endl;

    }
}

void White::CloseC()
{
    if (Credit) {
        if (debt < 1) {
            cout << "Your credit is closed";
            WithDraw(debt);
            debt = 0;
            termC = 0;
            percentC = 0;
            Credit = false;
        }
        else {
            int m;
            cout << "You have debt " << debt << " $";
            cout << "Do tou want to close debt(1-full,2-partly,3-no)?";
            cin >> m;
            if (m == 1) {
                WithDraw(debt);
                debt = 0;
                termC = 0;
                percentC = 0;
                Credit = false;
            }
            else if (m == 2) {
                float a;
                cout << "\nEnter sum: ";
                cin >> a;
                WithDraw(a);
                debt -= a;
            }
        }
    }
    else if (Credit == false) {
        int m;
        cout << "You dont have credit. Do you want to open?";
        cin >> m;
        if (m == 1)OpenC();
    }
}

void White::CloseD()
{
    if (Deposit) {
        TopUp(dep +( dep * percentD / 100)*termD);
        dep = 0;
        termD = 0;
        Deposit = false;
    }
    else if (Deposit == false) {
        int m;
        cout << "You dont have credit. Do you want to open?";
        cin >> m;
        if (m == 1)OpenD();
    }
}

string White::type() const
{
    return "White";
}

void White::show() const
{
    Card::show();
    cout << "Credit: ";if (Credit)cout << "yes\n";else if(Credit==false)cout << "no\n";
    cout << "Deposit: ";if (Deposit)cout << "yes\n";else if(Deposit==false)cout << "no\n";

}

void White::showDetails() const
{
    show();
    if (Credit) {
        cout << "Credit details: \n";
        cout << "Percent: " << percentC;
        cout << "\nTerm: " << termC;
        cout << "\nDebt: " << debt;
    }
    if (Deposit) {
        cout << "Deposit details: \n";
        cout << "Percent: " << percentD;
        cout << "\nTerm: " << termD;
        cout << "\nDeposit: " << dep;
    }
}

string White::toString() const
{
    return string();
}
