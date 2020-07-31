#pragma once
#include "Headers.h"

class CustomerBase
{
private:
    std::vector<std::shared_ptr<Client>> client;
    size_t count = 0;
public:
    CustomerBase() = default;
    ~CustomerBase() = default;
};
