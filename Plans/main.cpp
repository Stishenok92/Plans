#include "Headers.h"

int main()
{
    std::cout << "Task \"Mobile operator\"\n";
    
    Plan plan;
    std::ifstream file("Plan.txt");
    plan.read(file);
    file.close();
    
    ClientBase clientBase;
    file.open("Client.txt");
    clientBase.read(file, plan);
    file.close();
    
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
        "8. Edit client\n" <<
        "9. Remove client\n" <<
        "0. Exit\n" <<
        "\nEnter number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                clientBase.sortSurname();
                clientBase.save();
                break;
            case 1:
                menuPrintPlans(plan);
                break;
            case 2:
                menuSortPlans(plan);
                break;
            case 3:
                menuChoosePlan(plan);
                break;
            case 4:
                menuPrintClients(clientBase);
                break;
            case 5:
                menuSortClients(clientBase);
                break;
            case 6:
                std::cout << "\nCount clients: " <<
                clientBase.getCount() << "\n";
                break;
            case 7:
                menuAddClient(clientBase, plan);
                break;
            case 8:
                menuEditClient(clientBase, plan);
                break;
            case 9:
                menuEraseClient(clientBase);
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
