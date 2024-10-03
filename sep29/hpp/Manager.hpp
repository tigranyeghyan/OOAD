#pragma once
#include <stddef.h>

class Manager
{
public:
    virtual void removeEmployee(size_t id) = 0;
};