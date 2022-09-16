#pragma once
#include "Card.h"
class Ehelp :
    public Card
{
protected:

public:
    Ehelp();
    Ehelp(string name_, float money_);
    ~Ehelp();

    void Donate();

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;
    virtual void OpenC();
    virtual void OpenD();
    virtual void CloseC();
    virtual void CloseD();
    virtual void CashBack();
    virtual void Insurance();

    virtual string toString()const override;
};

