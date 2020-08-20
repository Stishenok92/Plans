#pragma once
#include "Headers.h"

class BasePlan
{
private:
    std::string name;                 //название тарифа
    double paymentMonthly;            //ежемесячный платеж
    double paymentStart;              //первоначальный авансовый платеж
    double costMinute;                //стоимость минуты исходящего вызова на мобильные телефоны внутри сети
    double costMinuteOtherOperator;   //стоимость минуты исходящего вызова на мобильные телефоны абонентов другого оператора
    double costMinuteCityPhone;       //стоимость минуты исходящего вызова на городские/стационарные телефоны
    double costSms;                   //стоимость исходящего сообщения на мобильные телефоны внутри сети
    double costSmsOtherOperator;      //стоимость исходящего сообщения на мобильные телефоны другово оператора
    double costMb;                    //стоимость 1 мб интернет трафика
public:
    BasePlan() = default;
    virtual ~BasePlan() = default;
    
    const std::string& getName() const { return name; }
    double getPaymentMonthly() const { return paymentMonthly; }
    double getPaymentStart() const { return paymentStart; }
    double getCostMinute() const { return costMinute; }
    double getCostMinuteOtherOperator() const { return costSmsOtherOperator; }
    double getCostMinuteCityPhone() const { return costMinuteCityPhone; }
    double getCostSms() const { return costSms; }
    double getCostSmsOtherOperator() const { return costSmsOtherOperator; }
    double getCostMb() const { return costMb; }
    
    void setName(const std::string& name) { this->name = name; }
    void setPaymentMonthly(double paymentMonthly) { this->paymentMonthly = paymentMonthly; }
    void setPaymentStart(double paymentStart) { this->paymentStart = paymentStart; }
    void setCostMinute(double costMinute) { this->costMinute = costMinute; }
    void setCostMinuteOtherOperator(double costSmsOtherOperator) { this->costSmsOtherOperator = costSmsOtherOperator; }
    void setCostMinuteCityPhone(double costMinuteCityPhone) { this->costMinuteCityPhone = costMinuteCityPhone; }
    void setCostSms(double costSms) { this->costSms = costSms; }
    void setCostSmsOtherOperator(double costSmsOtherOperator) { this->costSmsOtherOperator = costSmsOtherOperator; }
    void setCostMb(double costMb) { this->costMb = costMb; }
    
    virtual std::istream& read(std::istream&);
    virtual std::ostream& print(std::ostream&) const;
};

std::istream& BasePlan:: read(std::istream& in)
{
    in >> name >> paymentMonthly >> paymentStart >> costMinute >> costMinuteOtherOperator >> costMinuteCityPhone >> costSms >> costSmsOtherOperator >> costMb;
    return in;
}

std::ostream& BasePlan:: print(std::ostream& out) const
{
    out << std::left << std::setfill('.') << "\n" << "Name plan \"" << name << "\"\n" <<
    std::setw(35) << "Payment monthly" << std::setw(5) << std::right << paymentMonthly << std::left << " byn\n" <<
    std::setw(35) << "Payment start" << std::setw(5) << std::right << paymentStart << std::left << " byn\n" <<
    std::setw(35) << "Cost minute" << std::setw(5) << std::right << costMinute << std::left << " byn\n" <<
    std::setw(35) << "Cost minute (other operator)" << std::setw(5) << std::right << costMinuteOtherOperator << std::left << " byn\n" <<
    std::setw(35) << "Cost minute (city phone)" << std::setw(5) << std::right << costMinuteCityPhone << std::left << " byn\n" <<
    std::setw(35) << "Cost SMS" << std::setw(5) << std::right << costSms << std::left << " byn\n" <<
    std::setw(35) << "Cost SMS (other operator)" << std::setw(5) << std::right << costSmsOtherOperator << std::left << " byn\n" <<
    std::setw(35) << "Cost MB" << std::setw(5) << std::right << costMb << std::left << " byn" << std::setfill(' ');
    return out;
}


std::ostream& operator<<(std::ostream& out, std::shared_ptr<BasePlan> ptr)
{
    ptr->print(out);
    return out;
}
