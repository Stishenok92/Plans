#pragma once
#include "Headers.h"

std::shared_ptr<BasePlan> ptr(int);

class Plan
{
public:
    std::vector<std::shared_ptr<BasePlan>> plans;
    
    Plan() = default;
    ~Plan() = default;
    
    void read(std::istream&);
    void print(std::ostream&);
    void sortPaymentMonthly();
    void sortPaymentStart();
    void sortCostMinute();
    void sortCostMinuteOtherOperator();
    void sortCostMinuteCityPhone();
    void sortCostSms();
    void sortCostSmsOtherOperator();
    void sortCostMb();
};

std::shared_ptr<BasePlan> ptr(int choise)
{
    switch (choise)
    {
        case 0:
        {
            return std::make_shared<Easy>();
            break;
        }
        case 1:
        {
            return std::make_shared<EasySay>();
            break;
        }
        case 2:
        {
            return std::make_shared<EasyInternet>();
            break;
        }
        case 3:
        {
            return std::make_shared<EasySmart>();
            break;
        }
        default:
        {
            return nullptr;
        }
    }
}

void Plan:: read(std::istream& file)
{
    while (!file.eof())
    {
        int number;
        file >> number;
        plans.push_back(ptr(number));
        std::string str;
        getline(file, str);
        std::istringstream ss(str);
        plans.back()->read(ss);
    }
}

void Plan:: print(std::ostream& out)
{
    std::copy(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"));
}

void Plan:: sortPaymentMonthly()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getPaymentMonthly() > b->getPaymentMonthly(); });
}

void Plan:: sortPaymentStart()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getPaymentStart() > b->getPaymentStart(); });}

void Plan:: sortCostMinute()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMinute() > b->getCostMinute(); });}

void Plan:: sortCostMinuteOtherOperator()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSmsOtherOperator() > b->getCostSmsOtherOperator(); });
}

void Plan:: sortCostMinuteCityPhone()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMinuteCityPhone() > b->getCostMinuteCityPhone(); });
}

void Plan:: sortCostSms()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSms() > b->getCostSms(); });
}

void Plan:: sortCostSmsOtherOperator()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSmsOtherOperator() > b->getCostSmsOtherOperator(); });
}

void Plan:: sortCostMb()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMb() > b->getCostMb(); });
}
