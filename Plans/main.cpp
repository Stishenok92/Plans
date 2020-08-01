#include "Headers.h"

int main()
{
    std::cout << "Task \"Mobile operator\"\n";
    std::ifstream file("Plan.txt");
    
    if (!file)
    {
        std::cout << "Error opening file!\n";
        return 0;
    }
    
    Plan plan;
    plan.read(file);
    file.close();
    ClientBase clientBase;
    
    while (true)
    {
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Display plans\n" <<
        "2. Sort plans\n" <<
        "3. Display clients\n" <<
        "4. Sort clients\n" <<
        "5. Add client\n" <<
        "6. Remove client\n" <<
        "\nEnter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 1: //################################################ display plans
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
                
                break; //case 1
            }
            case 2: //################################################ sort plans
            {
                while (true)
                {
                    bool flag = true;
                    size_t operation;
                    std::cout << "\nOperation:\n" <<
                    "1. Sort for payment monthly\n" <<
                    "2. Sort for payment start\n" <<
                    "3. Sort for cost minute\n" <<
                    "4. Sort for cost minute other operator\n" <<
                    "5. Sort for cost minute city phone\n" <<
                    "6. Sort for cost sms\n" <<
                    "7. Sort for cost sms other operator\n" <<
                    "8. Sort for cost Mb\n" <<
                    "0. Exit in start menu\n\n" <<
                    "Enter number operation: ";
                    std::cin >> operation;
                    
                    switch (operation)
                    {
                        case 0:
                            break;
                        case 1:
                            plan.sortPaymentMonthly();
                            break;
                        case 2:
                            plan.sortPaymentStart();
                            break;
                        case 3:
                            plan.sortCostMinute();
                            break;
                        case 4:
                            plan.sortCostMinuteOtherOperator();
                            break;
                        case 5:
                            plan.sortCostMinuteCityPhone();
                            break;
                        case 6:
                            plan.sortCostSms();
                            break;
                        case 7:
                            plan.sortCostSmsOtherOperator();
                            break;
                        case 8:
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
                
                break; //case 2
            }
            case 3:
            {
                if (clientBase.getCount())
                {
                    clientBase.print(std::cout);
                }
                else
                {
                    std::cout << "\nClient base empty!\n";
                }
                
                break;
            }
            case 4:
            {
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
            case 5: //################################################ add client
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
                        std::cout << "\nError number plan!\n\n";
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
            case 6:
            {
                if (clientBase.getCount() == 0)
                {
                    std::cout << "\nClient base empty!\n";
                    break;
                }
                
                clientBase.sortSurname();
                size_t num;
                
                while (true)
                {
                    clientBase.print(std::cout);
                    std::cout << "\nEnter number position: ";
                    std::cin >> num;
                    
                    if (num < plan.getCount())
                        break;
                    else
                        std::cout << "\nError number position!\n\n";
                }
                
                clientBase.remove(num);
                std::cout << "\nClient successfully removed!\n";
                break;
            }
            default:
            {
                break;
            }
                
                
        }
        
        
    }
    
    
    
    
    system("pause");
    return 0;
}
