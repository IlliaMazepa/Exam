#pragma once
#include "Card.h"
class Black :
    public Card
{
protected:
    bool holder;
    string producer;
    float cashBack;
public:
    Black();
    Black(string name_, float money_,bool holder_,string producer_);
    ~Black();

    void setHolder(bool holder_);
    void setProducer(string producer_);

    bool getHolder()const;
    string getProducer()const;

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;
    void Donate();
    void CashBack();
    virtual void OpenC();
    virtual void OpenD();
    virtual void CloseC();
    virtual void CloseD();
    virtual void Insurance();


    virtual string toString() const override;
};

