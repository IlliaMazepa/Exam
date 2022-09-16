#pragma once
#include "Card.h"
class Dollar :
    public Card
{
protected:
    double ExchangeRate;
public:
    Dollar();
    Dollar(string name_, float money_);
    ~Dollar();

    void setEx(double Rate);

    double getEx()const;

    void TopUp(double a);
    void WithDraw(double a);

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;

    virtual void Donate();
    virtual void OpenC();
    virtual void OpenD();
    virtual void CloseC();
    virtual void CloseD();
    virtual void CashBack();
    virtual void Insurance();

    virtual string toString() const override;
};

