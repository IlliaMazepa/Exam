#pragma once
#include "Black.h"
class Platinum :
    public Black
{
protected:
    float cost;
    float perMonthPrice;
public:
    Platinum();
    Platinum(string name_, float money_, bool holder_, string producer_);
    ~Platinum();

    void setCost(float cost_);
    void setPrice(float perMonthPrice_);

    float getCost()const;
    float getPrice()const;

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;
    void CashBack();
    virtual void Insurance();

    virtual string toString() const override;
};

