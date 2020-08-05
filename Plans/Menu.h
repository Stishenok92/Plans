#pragma once
#include "Headers.h"

void planPrintMenu(const Plan& plan)
{
    while (true)
    {
        bool flag = true;
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Display all plans\n" <<
        "2. Display Easy plans\n" <<
        "3. Display EasySay plans\n" <<
        "4. Display EasyInternet plans\n" <<
        "5. Display EasySmart plans\n" <<
        "0. Exit in start menu\n" <<
        "\nEnter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                break;
            case 1:
                plan.print(std::cout);
                break;
            case 2:
                plan.printEasy(std::cout);
                break;
            case 3:
                plan.printEasySay(std::cout);
                break;
            case 4:
                plan.printEasyInternet(std::cout);
                break;
            case 5:
                plan.printEasySmart(std::cout);
                break;
            default:
                flag = false;
                std::cout << "\nError number operation!\n";
        }
        
        if (flag)
            break;
    }
}

void planSortMenu(Plan& plan)
{
    while (true)
    {
        bool flag = true;
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Sort for name\n" <<
        "2. Sort for payment monthly\n" <<
        "3. Sort for payment start\n" <<
        "4. Sort for cost minute\n" <<
        "5. Sort for cost minute other operator\n" <<
        "6. Sort for cost minute city phone\n" <<
        "7. Sort for cost sms\n" <<
        "8. Sort for cost sms other operator\n" <<
        "9. Sort for cost Mb\n" <<
        "0. Exit in start menu\n\n" <<
        "Enter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                return;
            case 1:
                plan.sortName();
                break;
            case 2:
                plan.sortPaymentMonthly();
                break;
            case 3:
                plan.sortPaymentStart();
                break;
            case 4:
                plan.sortCostMinute();
                break;
            case 5:
                plan.sortCostMinuteOtherOperator();
                break;
            case 6:
                plan.sortCostMinuteCityPhone();
                break;
            case 7:
                plan.sortCostSms();
                break;
            case 8:
                plan.sortCostSmsOtherOperator();
                break;
            case 9:
                plan.sortCostMb();
                break;
            default:
                flag = false;
                std::cout << "\nError number operation!\n";
        }
        
        if (flag)
        {
            std::cout << "\nSort completed successfully!\n";
            break;
        }
    }
}

void planChooseMenu(Plan& plan)
{
    while (true)
    {
        bool flag = true;
        size_t operation;
        std::cout << "\nChoose plan for:\n" <<
        "1. Payment monthly\n" <<
        "2. Payment start\n" <<
        "3. Cost minute\n" <<
        "4. Cost minute other operator\n" <<
        "5. Cost minute city phone\n" <<
        "6. Cost sms\n" <<
        "7. Cost sms other operator\n" <<
        "8. Cost Mb\n" <<
        "0. Exit in start menu\n\n" <<
        "Enter number operation: ";
        std::cin >> operation;
        double cost;
        
        switch (operation)
        {
            case 0:
                break;
            case 1:
                std::cout << "\nEnter payment mountly: ";
                std::cin >> cost;
                plan.choosePlanPaymentMonthly(cost);
                break;
            case 2:
                std::cout << "\nEnter payment start: ";
                std::cin >> cost;
                plan.choosePlanPaymentStart(cost);
                break;
            case 3:
                std::cout << "\nEnter cost minute: ";
                std::cin >> cost;
                plan.choosePlanCostMinute(cost);
                break;
            case 4:
                std::cout << "\nEnter cost minute other operator: ";
                std::cin >> cost;
                plan.choosePlanCostMinuteOtherOperator(cost);
                break;
            case 5:
                std::cout << "\nEnter cost minute city phone: ";
                std::cin >> cost;
                plan.choosePlanCostCityPhone(cost);
                break;
            case 6:
                std::cout << "\nEnter cost sms: ";
                std::cin >> cost;
                plan.choosePlanCostSms(cost);
                break;
            case 7:
                std::cout << "\nEnter cost sms other operator: ";
                std::cin >> cost;
                plan.choosePlanCostSmsOtherOperator(cost);
                break;
            case 8:
                std::cout << "\nEnter cost Mb: ";
                std::cin >> cost;
                plan.choosePlanCostMb(cost);
                break;
            default:
                flag = false;
                std::cout << "\nError number operation!\n";
        }
        
        if (flag)
        {
            break;
        }
    }
}

void clientsSortMenu(ClientBase& clientBase)
{
    if (clientBase.isEmpty())
        return;
    
    while (true)
    {
        bool flag = true;
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Sort for surname\n" <<
        "2. Sort for number\n" <<
        "3. Sort for plan\n" <<
        "0. Exit in start menu\n\n" <<
        "Enter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                break;
            case 1:
                clientBase.sortSurname();
                break;
            case 2:
                clientBase.sortNumber();
                break;
            case 3:
                clientBase.sortPlan();
                break;
            default:
                flag = false;
                std::cout << "\nError number operation!\n";
        }
        
        if (flag)
        {
            std::cout << "\nSort completed successfully!\n";
            break;
        }
    }
}

void clientsPrintMenu(const ClientBase& clientBase)
{
    if (!clientBase.isEmpty())
        clientBase.print(std::cout);
}

void clientAddMenu(ClientBase& clientBase, Plan& plan)
{
    std::string surname, name, patronymic, number;
    std::cout << "\nEnter surname: ";
    std::cin >> surname;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter patronymic: ";
    std::cin >> patronymic;
    number = clientBase.getNewNumber();
    size_t num;
    
    while (true)
    {
        plan.printWithIndex(std::cout);
        std::cout << "\nEnter number plan: ";
        std::cin >> num;
        
        if (num < plan.getCount())
            break;
        else
            std::cout << "\nError number plan!\n";
    }
    
    std::shared_ptr<Client> client = std::make_shared<Client>(surname, name, patronymic, number, plan[num]);
    clientBase.push(client);
    std::cout << "\nClient successfully added!\n";
}

void clientEraseMenu(ClientBase& clientBase, Plan& plan)
{
    if (clientBase.isEmpty())
        return;
    std::string number;
    
    while (true)
    {
        std::cout << "\nEnter client number (+375XXXXXXXXX): ";
        std::cin >> number;
        
        if (number.size() != 13)
        {
            std::cout << "\nError number input!\n";
            continue;
        }
        else
            break;
    }
    
    clientBase.eraseClient(number);
}

void clientEditMenu(ClientBase& clientBase, Plan& plan)
{
    if (clientBase.isEmpty())
        return;
    
    std::string number;
    
    while (true)
    {
        std::cout << "\nEnter client number (+375XXXXXXXXX): ";
        std::cin >> number;
        
        if (number.size() != 13)
        {
            std::cout << "\nError number input!\n";
            continue;
        }
        else
            break;
    }
    
    clientBase.editClient(number, plan);
}
