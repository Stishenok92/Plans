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
    file.close();
    std::cout << "\nPlans successfully imported!\n";
    
    ClientBase clientBase;
    
    while (true)
    {
        bool flag = false;
        size_t operation;
        std::cout << "\nOperation:\n" <<
        "1. Display plans\n" <<
        "2. Sort plans\n" <<
        "3. Choose plans\n" <<
        "4. Display clients\n" <<
        "5. Sort clients\n" <<
        "6. Count clients\n" <<
        "7. Add client\n" <<
        "8. Remove client\n" <<
        "0. Exit\n" <<
        "\nEnter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                break;
            case 1:
                planPrintMenu(plan);
                break;
            case 2:
                planSortMenu(plan);
                break;
            case 3:
                planChooseMenu(plan);
                break;
            case 4:
                clientsPrintMenu(clientBase);
                break;
            case 5:
                clientsSortMenu(clientBase);
                break;
            case 6:
                std::cout << "\nCount clients: " <<
                clientBase.getCount() << "\n";
                break;
            case 7:
                clientAddMenu(clientBase, plan);
                break;
            case 8:
                clientEraseMenu(clientBase, plan);
                break;
            default:
                std::cout << "\nError number operation!\n";
                break;
        }
        
        if (flag)
            break;
    }
    
    system("pause");
    return 0;
}
