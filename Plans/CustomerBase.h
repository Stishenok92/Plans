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
    void eraseClientForNumber(const std::string&);
    void sortSurname();
    void sortNumber();
    void sortPlan();
    
    size_t getCount() const { return clients.size(); }
};

void ClientBase:: print(std::ostream& out) const
{
    size_t cur = 0;
    out << "\n" << std::left <<
    std::setw(7) << "[№]" <<
    std::setw(20) << "Surname" <<
    std::setw(20) << "Name" <<
    std::setw(20) << "Patronymic" <<
    std::setw(20) << "Number" <<
    std::setw(20) << "Plan" <<
    std::setfill('-') << std::setw(100) << "\n" << std::setfill(' ');
    std::for_each(clients.begin(), clients.end(), [&cur, &out] (std::shared_ptr<Client> client)
                  {
        out << "\n" << "[" << cur++ << std::setw(3) << "]";
        out << client;
    });
    
    std::cout << "\n";
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

void ClientBase::eraseClientForNumber(const std::string& number)
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
    
    (*it)->printClient(std::cout);
    
    while (true)
    {
        char operation;
        std::cout << "\nDelete this client? (y/n): ";
        std::cin >> operation;
        
        if (operation == 'y')
        {
            clients.erase(it);
            std::cout << "\nСlient successfully deleted!\n";
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
