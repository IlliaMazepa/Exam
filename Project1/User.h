#pragma once
#include "Card.h"
#include "Black.h"
#include "Dollar.h"
#include "Ehelp.h"
#include "Euro.h"
#include "Iron.h"
#include "Platinum.h"
#include "White.h"
#include <vector>
#include <conio.h>

class User
{
protected:
	string name;
	string number;
	vector<Card*> Cards;
	string addresse;
	string password;
public:
	User();
	User(string name_,string number_,string addresse_,string password_);
	~User();

	void setName(string name_);
	void setNumber(string number_);
	void setAddresse(string addresse_);
	void setPassword(string password_);

	string getName()const;
	string getNumber()const;
	string getAddresse()const;
	string getPassword()const;

	void Creat();
	void DEl();

	void SignUp();
	bool SignIn(string num, string pass);
	void Top();
	void With();
	void Don();
	void EU();
	void USA();
	void Credit();
	void Deposit();
	void cashBack();
	void Ins();
	void Upgrade();
	void ChangeP();

	void showCard();
	void show();

	string type()const;
};

