#pragma once
#include "Headers.h"

class EasyInternet: public BasePlan
{
private:
    int packageMb;
public:
    EasyInternet() = default;
    ~EasyInternet() override = default;
    
    std::istream& read(std::istream&) override;
    std::ostream& print(std::ostream&) const override;
};

std::istream& EasyInternet:: read(std::istream& in)
{
    BasePlan:: read(in);
    in >> packageMb;
    return in;
}

std::ostream& EasyInternet:: print(std::ostream& out) const
{
    BasePlan::print(out);
    out << std::left << std::setfill('.') << "\n" <<
    std::setw(35) << "Package MB" << std::setw(9) << std::right << packageMb << std::setfill(' ') << std::left;
    return out;
}
