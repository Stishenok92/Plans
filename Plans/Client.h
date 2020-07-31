#pragma once
#include "Headers.h"

class Client
{
private:
    std::string surname;
    std::string name;
    std::string number;
    std::shared_ptr<BasePlan> plan;
public:
    Client() = default;
    ~Client() = default;
};
