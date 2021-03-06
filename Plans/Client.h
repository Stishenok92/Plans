#pragma once
#include "Headers.h"

class Client
{
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string number;
    std::shared_ptr<BasePlan> plan;
public:
    Client() = default;
    Client(std::string, std::string, std::string, std::string, std::shared_ptr<BasePlan> = nullptr);
    ~Client() = default;
    
    const std::string& getSurname() const { return surname; }
    const std::string& getName() const { return name; }
    const std::string& getPatronymic() const { return patronymic; }
    const std::string& getNumber() const { return number; }
    const std::shared_ptr<BasePlan>& getPlan() const { return plan; }
    
    void setSurname(const std::string& surname) { this->surname = surname; }
    void setName(const std::string& name) { this->name = name; }
    void setNumber(const std::string& number) { this->number = number; }
    void setPatronymic(const std::string& patronymic) { this->patronymic = patronymic; }
    void setPlan(const std::shared_ptr<BasePlan> plan) { this->plan = plan; }
    
    std::ostream& print(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, const Client&);
};

Client:: Client(std::string surname, std::string name, std::string patronymic, std::string number, std::shared_ptr<BasePlan> plan)
{
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->number = number;
    this->plan = plan;
}

std::ostream& Client:: print(std::ostream& out) const
{
    out << std::left << std::setfill('.') << "\n" << "Client information\n" <<
    std::setw(30) << "Surname" << std::setw(15) << std::right << surname << "\n" << std::left << std::setw(30) << "Name" <<
    std::setw(15) << std::right << name << "\n" << std::left << std::setw(30) << "Patronymic" <<
    std::setw(15) << std::right << patronymic << "\n" << std::left << std::setw(30) << "Number" <<
    std::setw(15) << std::right << number << "\n" << std::left <<
    std::setw(30) << "Plan" << std::setw(15) << std::right << plan->getName() << "\n" << std::setfill(' ') << std::left;
    return out;
}

std::ostream& operator<<(std::ostream& out, std::shared_ptr<Client> client)
{
    out << std::left <<
    std::setw(20) << client->getSurname() <<
    std::setw(20) << client->getName() <<
    std::setw(20) << client->getPatronymic() <<
    std::setw(20) << client->getNumber() <<
    std::setw(20) << client->getPlan()->getName();
    return out;
}
