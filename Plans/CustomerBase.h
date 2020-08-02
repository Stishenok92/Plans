#pragma once
#include "Headers.h"

class ClientBase
{
private:
    std::vector<std::shared_ptr<Client>> clients;
public:
    ClientBase() = default;
    ~ClientBase() = default;
    
    bool isEmpty();
    void print(std::ostream&);
    void printWithIndex(std::ostream&);
    void read(std::istream&);
    void save(std::ostream&);
    void push(const std::shared_ptr<Client>&);
    void remove(size_t);
    void sortSurname();
    void sortNumber();
    void sortPlan();
    size_t getCount() const { return clients.size(); }
};

void ClientBase:: print(std::ostream& out)
{
    size_t cur = 0;
    out << "\n" << std::left <<
    std::setw(7) << "[№]" <<
    std::setw(15) << "Surname" <<
    std::setw(15) << "Name" <<
    std::setw(20) << "Number" <<
    std::setw(15) << "Plan" <<
    std::setfill('-') << std::setw(70) << "\n" << std::setfill(' ');
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
}

void ClientBase:: remove(size_t index)
{
    clients.erase(clients.begin()+index);
}

void ClientBase:: sortSurname()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getSutname() < b->getSutname(); });
}

void ClientBase:: sortNumber()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getNumber() < b->getNumber(); });
}

void ClientBase:: sortPlan()
{
    std::sort(clients.begin(), clients.end(), [] (std::shared_ptr<Client> a, std::shared_ptr<Client> b) { return a->getPlan() < b->getPlan(); });
}

bool ClientBase:: isEmpty()
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

void ClientBase:: read(std::istream& file)
{
    while (!file.eof())
    {
//        int number;
//        file >> number;
//        plans.push_back(ptr(number));
//        std::string str;
//        getline(file, str);
//        std::istringstream ss(str);
//        plans.back()->read(ss);
    }
}

void ClientBase::save(std::ostream& file)
{
    std::copy(clients.begin(), clients.end(), std::ostream_iterator<std::shared_ptr<Client>>(file, " "));
}
