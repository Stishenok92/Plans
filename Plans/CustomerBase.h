#pragma once
#include "Headers.h"

class ClientBase
{
private:
    std::vector<std::shared_ptr<Client>> clients;
public:
    ClientBase() = default;
    ~ClientBase() = default;
    
    bool isEmpty() const;
    void print(std::ostream&) const;
    void addInFile(const std::shared_ptr<Client>&);
    void push(const std::shared_ptr<Client>&);
    void remove(size_t);
    bool checkNumber(const std::string&) const;
    std::string getNewNumber() const;
    void editClient(const std::string&, const Plan&);
    void eraseClient(const std::string&);
    void sortSurname();
    void sortNumber();
    void sortPlan();
    void save() const;
    
    size_t getCount() const { return clients.size(); }
};

std::ostream& linelong(std::ostream& out) //манипулятор вывода длинной линии
{
    out << std::left << std::setfill('-') << std::setw(100) << "-" << "\n" << std::setfill(' ');
    return out;
}

void ClientBase:: print(std::ostream& out) const
{
    size_t cur = 0;
    out << "\n" << linelong <<
    std::setw(7) << "[№]" <<
    std::setw(20) << "Surname" <<
    std::setw(20) << "Name" <<
    std::setw(20) << "Patronymic" <<
    std::setw(20) << "Number" <<
    std::setw(20) << "Plan" <<
    "\n" << linelong;
    
    std::for_each(clients.begin(), clients.end(), [&cur, &out] (std::shared_ptr<Client> client)
    {
        out << "[" << cur++ << std::setw(3) << "]";
        out << client << "\n";
    });
    
    out << linelong;
}

void ClientBase:: push(const std::shared_ptr<Client>& client)
{
    clients.push_back(client);
    addInFile(client);
}

void ClientBase:: remove(size_t index)
{
    clients.erase(clients.begin()+index);
}

void ClientBase:: sortSurname()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getSurname() < b->getSurname(); });
}

void ClientBase:: sortNumber()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getNumber() < b->getNumber(); });
}

void ClientBase:: sortPlan()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getPlan() < b->getPlan(); });
}

bool ClientBase:: isEmpty() const
{
    if (clients.size())
    {
        return false;
    }
    else
    {
        std::cout << "\nClient base empty!\n";
        return true;
    }
}

bool ClientBase::checkNumber(const std::string& number) const
{
    auto it = std::find_if(clients.begin(), clients.end(), [number] (std::shared_ptr<Client> client)
                           {
        return client->getNumber() == number;
    });
    
    if (it == clients.end())
        return true;
    else
        return false;
}

void ClientBase::addInFile(const std::shared_ptr<Client>& client)
{
    std::ofstream infile("Client.txt", std::ios::app);
    infile << std::left << "\n" <<
    std::setw(20) << client->getSurname() <<
    std::setw(20) << client->getName() <<
    std::setw(20) << client->getPatronymic() <<
    std::setw(20) << client->getNumber() <<
    std::setw(20) << client->getPlan()->getName();;
    infile.close();
}

void ClientBase::eraseClient(const std::string& number)
{
    auto it = std::find_if(clients.begin(), clients.end(), [number] (std::shared_ptr<Client> client)
                           {
        return client->getNumber() == number;
    });
    
    if (it == clients.end())
    {
        std::cout << "\nError! Сlient with this number is missing!\n";
        return;
    }
    
    (*it)->print(std::cout);
    
    while (true)
    {
        char operation;
        std::cout << "\nDelete this client? (y/n): ";
        std::cin >> operation;
        
        if (operation == 'y')
        {
            clients.erase(it);
            std::cout << "\nСlient successfully deleted!\n";
            this->save();
            return;
        }
        else if (operation == 'n')
        {
            return;
        }
        else
        {
            std::cout << "\nError command!\n";
        }
    }
}

void ClientBase::editClient(const std::string& number, const Plan& plan)
{
    auto it = std::find_if(clients.begin(), clients.end(), [number] (std::shared_ptr<Client> client)
                           {
        return client->getNumber() == number;
    });
    
    if (it == clients.end())
    {
        std::cout << "\nError! Сlient with this number is missing!\n";
        return;
    }
    
    (*it)->print(std::cout);
    
    while (true)
    {
        char operation;
        std::cout << "\nEdit this client? (y/n): ";
        std::cin >> operation;
        
        if (operation == 'y')
        {
            bool flag = false;
            
            while (true)
            {
                size_t operation;
                std::cout << "\nOperation:\n" <<
                "1. Edit surname\n" <<
                "2. Edit name\n" <<
                "3. Edit patronymic\n" <<
                "4. Edit number\n" <<
                "5. Edit plan\n" <<
                "6. Display client info\n" <<
                "0. Exit in start menu\n\n" <<
                "Enter number operation: ";
                std::cin >> operation;
                
                switch (operation)
                {
                    case 0:
                    {
                        if (flag)
                        {
                            this->sortSurname();
                            this->save();
                        }
                        
                        return;
                    }
                    case 1:
                    {
                        std::string str;
                        std::cout << "\nEnter new surname: ";
                        std::cin >> str;
                        (*it)->setSurname(str);
                        std::cout << "\nSurname changed successfully!\n";
                        flag = true;
                        break;
                    }
                    case 2:
                    {
                        std::string str;
                        std::cout << "\nEnter new name: ";
                        std::cin >> str;
                        (*it)->setName(str);
                        std::cout << "\nName changed successfully!\n";
                        flag = true;
                        break;
                    }
                    case 3:
                    {
                        std::string str;
                        std::cout << "\nEnter new patronymic: ";
                        std::cin >> str;
                        (*it)->setPatronymic(str);
                        std::cout << "\nPatronymic changed successfully!\n";
                        flag = true;
                        break;
                    }
                    case 4:
                    {
                        std::string str;
                        str = this->getNewNumber();
                        (*it)->setNumber(str);
                        std::cout << "\nNumber changed successfully!\n";
                        flag = true;
                        break;
                    }
                    case 5:
                    {
                        while (true)
                        {
                            size_t num;
                            plan.printWithIndex(std::cout);
                            std::cout << "\nEnter number plan: ";
                            std::cin >> num;
                            
                            if (num < plan.getCount())
                            {
                                (*it)->setPlan(plan[num]);
                                std::cout << "\nPlan changed successfully!\n";
                                flag = true;
                                break;
                            }
                            else
                                std::cout << "\nError number plan!\n";
                        }
                        
                        break;
                    }
                    case 6:
                    {
                        (*it)->print(std::cout);
                        break;
                    }
                    default:
                    {
                        std::cout << "\nError number operation!\n";
                    }
                }
            }
        }
        else if (operation == 'n')
        {
            return;
        }
        else
        {
            std::cout << "\nError command!\n";
        }
    }
}

void ClientBase::save() const
{
    std::ofstream file("Client2.txt");
    file << std::left <<
    std::setw(20) << "Surname" <<
    std::setw(20) << "Name" <<
    std::setw(20) << "Patronymic" <<
    std::setw(20) << "Number" <<
    std::setw(20) << "Plan" << "\n";
    std::copy(clients.begin(), clients.end(), std::ostream_iterator<std::shared_ptr<Client>>(file, "\n"));
    file.close();
}

std::string ClientBase:: getNewNumber() const
{
    std::string code, number;
    while (true)
    {
        bool flag = true;
        std::size_t operation;
        std::cout << "\nPossible code:\n" <<
        "1. +37525\n" <<
        "2. +37529\n" <<
        "3. +37544\n" <<
        "4. +37533\n" <<
        "\nEnter number code: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 1:
                code = "+37525";
                break;
            case 2:
                code = "+37529";
                break;
            case 3:
                code = "+37544";
                break;
            case 4:
                code = "+37533";
                break;
            default:
                flag = false;
                std::cout << "\nError number code!\n";
        }
        
        if (flag)
            break;
    }
    
    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> number;
        
        if (number.size() == 7)
        {
            number = code + number;
        }
        else
        {
            std::cout << "\nError number input!\n\n";
            continue;
        }
        
        if (checkNumber(number))
            break;
        else
            std::cout << "\nError! This number already used!\n\n";
    }
    
    return number;
}
