#pragma once
#include "Headers.h"

class EasySay: public BasePlan
{
private:
    int packageMinute;
    int packageSms;
public:
    EasySay() = default;
    ~EasySay() override = default;
    
    std::istream& read(std::istream&) override;
    std::ostream& print(std::ostream&) const override;
};

std::istream& EasySay:: read(std::istream& in)
{
    BasePlan:: read(in);
    in >> packageMinute >> packageSms;
    return in;
}

std::ostream& EasySay:: print(std::ostream& out) const
{
    BasePlan::print(out);
    out << std::left << std::setfill('.') << "\n" <<
    std::setw(35) << "Package minute" << packageMinute << "\n" <<
    std::setw(35) << "Package sms" << packageSms;
    return out;
}
