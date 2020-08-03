#include "Headers.h"

int main()
{
    std::cout << "Task \"Mobile operator\"\n";
    std::ifstream file("Plan.txt");
    
    if (!file)
    {
        std::cout << "Error opening file Plan.txt!\n";
        return 0;
    }
    
    Plan plan;
    plan.read(file);
    std::cout << "\nPlans successfully imported!\n";
    file.close();
    
    ClientBase clientBase;
    
    while (true)
    {
        bool flag = false;
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Display plans\n" <<
        "2. Sort plans\n" <<
        "3. Choose plan for parameters\n" <<
        "4. Display clients\n" <<
        "5. Counting clients\n" <<
        "6. Sort clients\n" <<
        "7. Add client\n" <<
        "8. Remove client\n" <<
        "9. Save clients in file\n"
        "0. Exit\n" <<
        "\nEnter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
            {
                flag = true;
                break;
            }
            case 1:
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
                
                break;
            }
            case 2:
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
                            break;
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
                
                break;
            }
            case 3:
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
                
                break;
            }
            case 4:
            {
                if (!clientBase.isEmpty())
                {
                    clientBase.print(std::cout);
                }
                
                break;
            }
            case 5:
            {
                std::cout << "\nNumber of clients: " << clientBase.getCount() << "\n";
                break;
            }
            case 6:
            {
                if (clientBase.isEmpty())
                    break;
                
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
                break;
            }
            case 7:
            {
                std::string surname, name, number = "+37525", temp_number;
                std::cout << "\nEnter surname: ";
                std::cin >> surname;
                std::cout << "Enter name: ";
                std::cin >> name;
                
                while (true)
                {
                    std::cout << "Enter number (7 digits): ";
                    std::cin >> temp_number;
                    
                    if (temp_number.size() == 7)
                    {
                        number += temp_number;
                        break;
                    }
                    else
                    {
                        std::cout << "\nError number input!\n\n";
                    }
                }
                
                plan.sortName();
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
                
                std::shared_ptr<Client> client = std::make_shared<Client>();
                client->setSurname(surname);
                client->setName(name);
                client->setNumber(number);
                client->setPlan(plan[num]);
                clientBase.push(client);
                std::cout << "\nClient successfully added!\n";
                break;
            }
            case 8:
            {
                if (clientBase.isEmpty())
                    break;
                
                size_t num;
                
                while (true)
                {
                    clientBase.print(std::cout);
                    std::cout << "\nEnter number position: ";
                    std::cin >> num;
                    
                    if (num < clientBase.getCount())
                        break;
                    else
                        std::cout << "\nError number position!\n";
                }
                
                clientBase.remove(num);
                std::cout << "\nClient successfully removed!\n";
                break;
            }
            case 9:
            {
                if (clientBase.isEmpty())
                    break;
                std::ofstream fileout("Client.txt");
                clientBase.save(fileout);
                fileout.close();
                std::cout << "\nClients successfully exported from file Client.txt!\n";
                break;
                
            }
            default:
            {
                std::cout << "\nError number operation!\n";
                break;
            }
        }
        
        if (flag)
            break;
    }
    
    system("pause");
    return 0;
}
