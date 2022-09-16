#pragma once
#include "Platinum.h"
class Iron :
    public Platinum
{
protected:
    float cost;
    float perMonthPrice;
    bool insur;
    bool car;
public:
    Iron();
    Iron(string name_, float money_, bool holder_, string producer_,bool car_);
    ~Iron();

    void setCar(bool car_);

    bool getCar()const;

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;
    void Insurance();

    virtual string toString() const override;
};

