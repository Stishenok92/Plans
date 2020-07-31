#include "Headers.h"

int main()
{
    std::cout << "Task \"Mobile operator\"\n\n";
    std::ifstream file("Plan.txt");
    
    if (!file)
    {
        std::cout << "Error opening file!\n";
        return 0;
    }
    
    Plan plans;
    plans.read(file);
    file.close();
    
    plans.print(std::cout);
    
    
    system("pause");
    return 0;
}
