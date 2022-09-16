 #pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Card
{
protected:
	string name;
	string number;
	float money;
	string pin;
public:
	Card();
	Card(string name_,float money_);
	~Card();

	void setName(string name_);
	void setNumber(string number_);
	void setMoney(float money_);
	void setPin(string pin_);

	string getName()const;
	string getNumber()const;
	float getMoney()const;
	string getPin()const;

	void Change_PIN();
	void TopUp();
	void TopUp(float a);
	void WithDraw();
	void WithDraw(float a);
	virtual void Donate() = 0;
	virtual void OpenC() = 0;
	virtual void OpenD() = 0;
	virtual void CloseC() = 0;
	virtual void CloseD() = 0;
	virtual void CashBack() = 0;
	virtual void Insurance() = 0;


	virtual string type()const = 0;
	void show()const;
	virtual void showDetails()const=0;

	virtual string toString()const = 0;
};

