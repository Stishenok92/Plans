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

void Plan:: print(std::ostream& out) const
{
    std::copy(plans.begin(), plans.end(), std::ostream_iterator<std::shared_ptr<BasePlan>>(out, "\n"));
}

void Plan:: printWithIndex(std::ostream& out) const
{
    size_t num = 0;
    std::cout << "\n[№] Plan\n------------------\n";
    std::for_each(plans.begin(), plans.end(), [&num] (std::shared_ptr<BasePlan> temp_plan){ std::cout << "[" << num++ << "] " << temp_plan->getName() << "\n";});
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

bool Plan:: isEmpty() const
{
    if (plans.size())
    {
        return false;
    }
    else
    {
        std::cout << "\nSorry, no suitable plans!\n";
        return true;
    }
}

void Plan:: choosePlanPaymentMonthly(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getPaymentMonthly() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortPaymentMonthly();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanPaymentStart(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getPaymentStart() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortPaymentStart();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMinute(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostMinute() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinute();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMinuteOtherOperator(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostMinuteOtherOperator() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinuteOtherOperator();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostCityPhone(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostMinuteCityPhone() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMinuteCityPhone();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostSms(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostSms() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostSms();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostSmsOtherOperator(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostSmsOtherOperator() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostSmsOtherOperator();
        temp_plan.print(std::cout);
    }
}

void Plan:: choosePlanCostMb(double cost) const
{
    Plan temp_plan;
    std::for_each(plans.begin(), plans.end(), [cost, &temp_plan] (std::shared_ptr<BasePlan> plan)
                  {
        if (plan->getCostMb() <= cost)
            temp_plan.plans.push_back(plan);
    });
    
    if (!temp_plan.isEmpty())
    {
        temp_plan.sortCostMb();
        temp_plan.print(std::cout);
    }
}
