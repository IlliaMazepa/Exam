#pragma once
#include "Card.h"
class White :
    public Card
{
protected:
    float percentC;
    float percentD;
    bool Credit;
    bool Deposit;
    int termC;
    int termD;
    double debt;
    double dep;
    string producer;
public:
    White();
    White(string name_, float money_, string producer_);
    ~White();

    void setPrecentC(float percentC_);
    void setPrecentD(float percentD_);
    void setC(bool Credit_);
    void setD(bool Deposit_);
    void setTermC(int termC_);
    void setTermD(int termD_);
    void setDebt(double debt_);
    void setDep(double dep_);
    void setProducer(string producer_);

    float getPercentC()const;
    float getPercentD()const;
    bool getC()const;
    bool getD()const;
    int getTermC()const;
    int getTermD()const;
    double getDebt()const;
    double getDep()const;
    string getProducer()const;
    virtual void CashBack();
    virtual void Insurance();
    virtual void Donate();

    void OpenC();
    void OpenD();

    void CloseC();
    void CloseD();

    virtual string type()const override;
    void show()const;
    virtual void showDetails()const override;


    virtual string toString() const override;
};

