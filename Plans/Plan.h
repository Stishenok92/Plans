#pragma once
#include "Headers.h"

std::shared_ptr<BasePlan> ptr(int);

class Plan
{
    
private:
    std::vector<std::shared_ptr<BasePlan>> plans;
public:
    Plan() = default;
    ~Plan() = default;
    
    size_t getCount() const { return plans.size(); }
    void read(std::istream&);
    void print(std::ostream&);
    void printWithIndex(std::ostream&);
    void printEasy(std::ostream&);
    void printEasySay(std::ostream&);
    void printEasyInternet(std::ostream&);
    void printEasySmart(std::ostream&);
    void sortName();
    void sortPaymentMonthly();
    void sortPaymentStart();
    void sortCostMinute();
    void sortCostMinuteOtherOperator();
    void sortCostMinuteCityPhone();
    void sortCostSms();
    void sortCostSmsOtherOperator();
    void sortCostMb();
    const std::shared_ptr<BasePlan>& operator[](size_t) const;
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

void Plan:: printWithIndex(std::ostream& out)
{
    size_t num = 0;
    std::cout << "\n[№] Plan\n------------------\n";
    std::for_each(plans.begin(), plans.end(), [&num] (std::shared_ptr<BasePlan> temp_plan){ std::cout << "[" << num++ << "] " << temp_plan->getName() << "\n";});
}

void Plan:: printEasy(std::ostream& out)
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(Easy)); });
}

void Plan:: printEasySay(std::ostream& out)
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(EasySay)); });
}

void Plan:: printEasyInternet(std::ostream& out)
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(EasyInternet)); });
}

void Plan:: printEasySmart(std::ostream& out)
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(EasySmart)); });
}

void Plan:: sortName()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getName() < b->getName(); });
}

void Plan:: sortPaymentMonthly()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getPaymentMonthly() < b->getPaymentMonthly(); });
}

void Plan:: sortPaymentStart()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getPaymentStart() < b->getPaymentStart(); });}

void Plan:: sortCostMinute()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMinute() < b->getCostMinute(); });}

void Plan:: sortCostMinuteOtherOperator()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSmsOtherOperator() < b->getCostSmsOtherOperator(); });
}

void Plan:: sortCostMinuteCityPhone()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMinuteCityPhone() < b->getCostMinuteCityPhone(); });
}

void Plan:: sortCostSms()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSms() < b->getCostSms(); });
}

void Plan:: sortCostSmsOtherOperator()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostSmsOtherOperator() < b->getCostSmsOtherOperator(); });
}

void Plan:: sortCostMb()
{
    std::sort(plans.begin(), plans.end(), [] (std::shared_ptr<BasePlan> a, std::shared_ptr<BasePlan> b) { return a->getCostMb() < b->getCostMb(); });
}

const std::shared_ptr<BasePlan>& Plan:: operator[](size_t index) const
{
    return plans[index];
}
