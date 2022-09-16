#include "User.h"

User::User()
{
    name = "";
    number = "";
    addresse = "";
    password = "";
}

User::User(string name_, string number_, string addresse_, string password_)
{
    /*int str;*/
    name = name_;
    number = number_;
    addresse = addresse_;
    password = password_;
    Cards.reserve(100);
   /* cout << "MasterCard(1) or Visa(2)";
    cin >> str;
    if (str == 1) Cards.push_back(new Black(name, 0, false, "M"));
    else if (str == 2) Cards.push_back(new Black(name, 0, false, "V"));*/
}

User::~User()
{
}

void User::setName(string name_)
{
    name = name_;
    
}

void User::setNumber(string number_)
{
    number = number_;
    
}

void User::setAddresse(string addresse_)
{
    addresse = addresse_;
    
}

void User::setPassword(string password_)
{
    password = password_;
}

string User::getName() const
{
    return name;
}

string User::getNumber() const
{
    return number;
}

string User::getAddresse() const
{
    return addresse;
}

string User::getPassword() const
{
    return password;
}

void User::Creat()
{
    int menu;
    vector<Card*>::iterator i;
    cout << "\nChoose card type: \n";
    cout << "1. White\n 2. EHelp\n 3. Dollar\n 4.Euro\n";
    cin >> menu;
    if (menu == 1) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "White") {
                cout << "You already has this card";
                Creat();
                i = Cards.begin();
                break;
            }
            
        }
        
        if (i == Cards.end()) {

            int str;
            cout << "MasterCard(1) or Visa(2)";
            cin >> str;

            if (str == 1) Cards.push_back(new White(name, 0, "M"));
            else if (str == 2) Cards.push_back(new White(name, 0, "V"));

        }
    }
    ////////////////////
    if (menu == 2) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
      
          if ((*i)->type() == "EHelp") {
              cout << "You already has this card";
              Creat();
              i = Cards.begin();
              break;
          }
            
        }
        
        if (i == Cards.end()) {
            Cards.push_back(new Ehelp(name, 0));
        }
    }
    ////////////////////
    else if (menu == 3) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Dollar") {
                cout << "You already has this card";
                Creat();
                i = Cards.begin();
                break;
            }
           
        }
        
    if (i == Cards.end()) {
        Cards.push_back(new Dollar(name, 40));
    }
    }
    else if (menu == 4) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Euro" ) {
                cout << "You already has this card";
                Creat();
                i = Cards.begin();
                break;
            }
            
        }
       
    if (i == Cards.end()) {
        Cards.push_back(new Euro(name, 41));
    }
    }
}

void User::DEl()
{
    int menu;
    vector<Card*>::iterator i;
    cout << "\nChoose card type: \n";
    cout << "1. White\n 2. EHelp\n 3. Dollar\n 4.Euro\n";
    cin >> menu;
    if (menu == 1) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "White") {
                Cards.erase(i);
                cout << "Succesfuly";
                i = Cards.begin();
                break;
            }

        }
        if (i == Cards.end()) {
            cout << "You dont has this card";
        }
    }
    ////////////////////
    else if (menu == 2) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "EHelp") {
                Cards.erase(i);
                cout << "Succesfuly";
                i = Cards.begin();
                break;
            }

        }
        if (i == Cards.end()) {
            cout << "You dont has this card";
        }
    }
    ////////////////////
    else if (menu == 3) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Dollar") {
                Cards.erase(i);
                cout << "Succesfuly";
                i = Cards.begin();
                break;
            }

        }
        if (i == Cards.end()) {
            cout << "You dont has this card";
        }
    }
    else if (menu == 4) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Euro") {
                Cards.erase(i);
                cout << "Succesfuly";
                i = Cards.begin();
                break;
            }

        }
        if (i == Cards.end()) {
            cout << "You dont has this card";
        }
    }
}

void User::SignUp()
{
    
   
    int str;
    cout << "MasterCard(1) or Visa(2)";
    cin >> str;
    if (str == 1) Cards.push_back(new Black(name, 0,false, "M"));
    else if (str == 2) Cards.push_back(new Black(name, 0,false, "V"));
}

bool User::SignIn(string num, string pass)
{
    if (num == number && pass == password) {
        cout << "\n\tWellcome\n";
        return true;
    }
    else {
        cout << "Wrong password or number";
        return false;
    }
}

void User::Top()
{
    vector<Card*>::iterator i;
    cout << "Choose card: ";
    for (i = Cards.begin(); i != Cards.end();) {
        system("CLS");
        cout<<(*i)->type()<<endl;
        if (_getch() == 13) break;
        else if (_getch() == 77&&i!=Cards.end())i++;
        else if (_getch() == 75&&i!=Cards.begin())i--;
    }
    (*i)->TopUp();
}

void User::With()
{
    vector<Card*>::iterator i;
    cout << "Choose card: ";
    for (i = Cards.begin(); i != Cards.end();) {
        system("CLS");
        cout << (*i)->type() << endl;
        if (_getch() == 13) break;
        else if (_getch() == 77 && i != Cards.end())i++;
        else if (_getch() == 75 && i != Cards.begin())i--;
    }
    (*i)->WithDraw();
}

void User::Don()
{
    int sum = 0;
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "Black")sum += 1;
        else if ((*i)->type() == "EHelp")sum += 2;
    }
    if (sum == 1) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Black") {
                (*i)->Donate();
            }
        }
    }
    else if (sum == 2) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "EHelp") {
                (*i)->Donate();
            }
        }
    }
    else if (sum == 3) {
        system("CLS");
        cout << "Black\tEHelp";
        if (_getch() == 77) {
            for (i = Cards.begin(); i != Cards.end(); i++) {
                if ((*i)->type() == "EHelp")(*i)->Donate();
            }
        }
        else if(_getch() == 75) {
        if ((*i)->type() == "Black")(*i)->Donate();
        }
    }
   
}

void User::EU()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end();i++) {
        system("CLS");
        if ((*i)->type() == "Euro") {
            cout << "TopUp\tWithdraw";
        if (_getch() == 77)(*i)->WithDraw();
        else if (_getch() == 75)(*i)->TopUp();
        }
    }
}

void User::USA()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "Dollar") {
            cout << "TopUp\tWithdraw";
            if (_getch() == 77)(*i)->WithDraw();
            else if (_getch() == 75)(*i)->TopUp();
        }
    }
}

void User::Credit()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "White") {
            cout << "Open\tClose";
            if (_getch() == 77)(*i)->CloseC();
            else if (_getch() == 75)(*i)->OpenC();
        }
    }
   
}

void User::Deposit()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "White") {
            cout << "Open\tClose";
            if (_getch() == 77)(*i)->CloseD();
            else if (_getch() == 75)(*i)->OpenD();
        }
    }
}

void User::cashBack()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "Iron"|| (*i)->type() == "Platinum"|| (*i)->type() == "Black") {
            (*i)->CashBack();
        }
    }
}

void User::Ins()
{
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if ((*i)->type() == "Iron") {
            (*i)->Insurance();

        }
    }
}

void User::Upgrade()
{
    int h;
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        if (( * i)->type() == "Black" || (*i)->type() == "Platinum") {
            if ((*i)->type() == "Black") {
                cout << "Choose new card:\n (1)Platinum\t(2)Iron";
                cin >> h;
                if (h==2)
                {
                    string a;
                    float b;
                    int c;
                    b = (*i)->getMoney();
                    cout << "MasterCard(1) or Visa(2)";
                    cin >> a;
                    cout << "Do you have car?\n1-Yes\t0-No";
                    cin >> c;
                    Cards.erase(i);
                    if(c==1) Cards.push_back(new Iron(name, b, true, a, true));
                    else if(c==1) Cards.push_back(new Iron(name, b, true, a, false));
                    break;
                    
                }
                else if (h == 1) {
                    string a;
                    float b;
                    int c;
                    b = (*i)->getMoney();
                    cout << "MasterCard(1) or Visa(2)";
                    cin >> a;

                    Cards.push_back(new Platinum(name, b, true, a));
                    Cards.erase(i);


                    break;
                }
            }
            else if ((*i)->type() == "Platinum") {
                    string a;
                    float b;
                    int c;
                    b = (*i)->getMoney();
                    cout << "MasterCard(1) or Visa(2)";
                    cin >> a;
                    cout << "Do you have car?\n1-Yes\t0-No";
                    cin >> c;
                    Cards.push_back(new Iron(name, b, true, a, c));
                    Cards.erase(i);
                    break;
      
            }
 
        }
    }
}

void User::ChangeP()
{
    int menu;
    vector<Card*>::iterator i;
    cout << "\nChoose card type: \n";
    cout << "1. White\n 2. EHelp\n 3. Dollar\n 4.Euro\n5.Black\n";
    cin >> menu;
    if (menu == 1) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "White") {
                (*i)->Change_PIN();
                i = Cards.begin();
                break;
            }

        }

        if (i == Cards.end()) {

            cout << "Ypu dont have this card";

        }
    }
    if (menu == 2) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "EHelp") {
                (*i)->Change_PIN();
                i = Cards.begin();
                break;
            }

        }

        if (i == Cards.end()) {

            cout << "Ypu dont have this card";

        }
    }
    if (menu == 3) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Dollar") {
                (*i)->Change_PIN();
                i = Cards.begin();
                break;
            }

        }

        if (i == Cards.end()) {

            cout << "Ypu dont have this card";

        }
    }
    if (menu == 4) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Euro") {
                (*i)->Change_PIN();
                i = Cards.begin();
                break;
            }

        }

        if (i == Cards.end()) {

            cout << "Ypu dont have this card";

        }
    }
    if (menu == 5) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            if ((*i)->type() == "Black") {
                (*i)->Change_PIN();
                i = Cards.begin();
                break;
            }

        }

        if (i == Cards.end()) {

            cout << "Ypu dont have this card";

        }
    }
}

void User::showCard() 
{
    int a;
    vector<Card*>::iterator i;
    for (i = Cards.begin(); i != Cards.end(); i++) {
        (*i)->show();
    }
    cout << "Do you want full info?(1-yes  2-no)";
    cin >> a;
    system("CLS");
    if (a == 1) {
        for (i = Cards.begin(); i != Cards.end(); i++) {
            (*i)->showDetails();
        }
    }
}

void User::show() 
{
    int a;
    cout << "\nName: " << name << endl;
    cout << "Telephone number: " << number << endl;
    cout << "Addresse: " << addresse << endl;
    cout << "Password: " << password << endl;
    cout << "Do you want to see all cards: "; cin >> a;
    if (a == 1) {
        showCard();
        system("pause");
    }
}

string User::type() const
{
    return "User";
}
