#pragma once
#include "Headers.h"

class Plan
{
private:
    std::vector<std::shared_ptr<BasePlan>> plans;
public:
    Plan() = default;
    ~Plan() = default;
    
    bool isEmpty() const;
    void read(std::istream&);
    
    void print(std::ostream&) const;
    void printWithIndex(std::ostream&) const;
    void printEasy(std::ostream&) const;
    void printEasySay(std::ostream&) const;
    void printEasyInternet(std::ostream&) const;
    void printEasySmart(std::ostream&) const;
    
    void sortName();
    void sortPaymentMonthly();
    void sortPaymentStart();
    void sortCostMinute();
    void sortCostMinuteOtherOperator();
    void sortCostMinuteCityPhone();
    void sortCostSms();
    void sortCostSmsOtherOperator();
    void sortCostMb();
    
    void choosePlanPaymentMonthly(double) const;
    void choosePlanPaymentStart(double) const;
    void choosePlanCostMinute(double) const;
    void choosePlanCostMinuteOtherOperator(double) const;
    void choosePlanCostCityPhone(double) const;
    void choosePlanCostSms(double) const;
    void choosePlanCostSmsOtherOperator(double) const;
    void choosePlanCostMb(double) const;
    
    const std::shared_ptr<BasePlan>& operator[](size_t) const;
    size_t getCount() const { return plans.size(); }
};

std::ostream& line(std::ostream& out) //манипулятор вывода линии
{
    out << std::left << std::setfill('-') << std::setw(44) << "-" << "\n" << std::setfill(' ');
    return out;
}

std::shared_ptr<BasePlan> ptr(int choise)
{
    switch (choise)
    {
        case 0:
            return std::make_shared<Easy>();
        case 1:
            return std::make_shared<EasySay>();
        case 2:
            return std::make_shared<EasyInternet>();
        case 3:
            return std::make_shared<EasySmart>();
        default:
            return nullptr;
    }
}

bool Plan:: isEmpty() const
{
    if (plans.size())
        return false;
    else
    {
        std::cout << "\nSorry, no suitable plans!\n";
        return true;
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

void Plan:: print(std::ostream& out) const
{
    std::copy(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"));
}

void Plan:: printWithIndex(std::ostream& out) const
{
    size_t num = 0;
    out << "\n" << line << "[№]  Plan" << "\n" << line;
    std::for_each(plans.begin(), plans.end(), [&num, &out] (std::shared_ptr<BasePlan> temp_plan) { out << "[" << num++ << "]  " << temp_plan->getName() << "\n";});
    out << line;
}

void Plan:: printEasy(std::ostream& out) const
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(Easy)); });
}

void Plan:: printEasySay(std::ostream& out) const
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(EasySay)); });
}

void Plan:: printEasyInternet(std::ostream& out) const
{
    std::copy_if(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"), [] (std::shared_ptr<BasePlan> plan) { return (typeid(*plan) == typeid(EasyInternet)); });
}

void Plan:: printEasySmart(std::ostream& out) const
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

void Plan:: choosePlanPaymentMonthly(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getPaymentMonthly() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortPaymentMonthly();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanPaymentStart(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getPaymentStart() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortPaymentStart();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMinute(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostMinute() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinute();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMinuteOtherOperator(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostMinuteOtherOperator() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinuteOtherOperator();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostCityPhone(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostMinuteCityPhone() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinuteCityPhone();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostSms(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostSms() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostSms();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostSmsOtherOperator(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostSmsOtherOperator() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostSmsOtherOperator();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMb(double cost) const
{
    Plan temp_plan;
    std::copy_if(plans.begin(), plans.end(), std::back_inserter(temp_plan.plans), [cost] (std::shared_ptr<BasePlan> plan) { return plan->getCostMb() <= cost; });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMb();
        temp_plan.print(std::cout);
    }
}
