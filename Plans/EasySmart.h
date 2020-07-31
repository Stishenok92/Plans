#pragma once
#include "Headers.h"

class EasySmart: public BasePlan
{
private:
    int packageMinute;
    int packageSms;
    int packageMb;
public:
    EasySmart() = default;
    ~EasySmart() override = default;
    std::istream& read(std::istream&) override;
    std::ostream& print(std::ostream&) const override;
};

std::istream& EasySmart:: read(std::istream& in)
{
    BasePlan:: read(in);
    in >> packageMinute >> packageSms >> packageMb;
    return in;
}

std::ostream& EasySmart:: print(std::ostream& out) const
{
    BasePlan::print(out);
    out << std::left << std::setfill('.') << "\n" <<
    std::setw(35) <<"Package minute" << packageMinute << "\n" <<
    std::setw(35) <<"Package sms" << packageSms << "\n" <<
    std::setw(35) <<"Package Mb" << packageMb;
    return out;
}
