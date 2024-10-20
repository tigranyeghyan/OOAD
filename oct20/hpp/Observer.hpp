#pragma once
#include <utility>
#include <string>

class Observer
{
public:
    virtual void update(std::pair<std::string, double> stock_update) = 0;
    virtual void subscribe(const std::string& stock) = 0;
    virtual void unsubscribe(const std::string& stock) = 0;
protected:
    Observer(const std::string& name);
    std::string name;
};