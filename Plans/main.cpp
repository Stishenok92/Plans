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
    
    Plan plans;
    plans.read(file);
    file.close();
    
    while (true)
    {
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Display plans\n\n" <<
        "Enter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 1:
            {
                size_t operation;
                std::cout << "\nOperation:\n" <<
                "1. Display all plans\n" <<
                "2. Display Easy plans\n" <<
                "3. Display EasySay plans\n" <<
                "4. Display EasyInternet plans\n" <<
                "5. Display EasySmart plans\n" <<
                "0. Exit in menu\n\n" <<
                "Enter number operation: ";
                std::cin >> operation;
                
                switch (operation)
                {
                    case 1:
                    {
                        plans.print(std::cout);
                        break;
                    }
                    case 2:
                    {
                        plans.printEasy(std::cout);
                        break;
                    }
                    case 3:
                    {
                        plans.printEasySay(std::cout);
                        break;
                    }
                    case 4:
                    {
                        plans.printEasyInternet(std::cout);
                        break;
                    }
                    case 5:
                    {
                        plans.printEasySmart(std::cout);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
                
            default:
                break;
        }
        
        
    }
    
    
    
    
    system("pause");
    return 0;
}
