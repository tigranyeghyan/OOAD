#pragma once
#include "Observer.hpp"
#include <string>

class AIBot : public Observer
{
public:
    AIBot(const std::string& name);
    void update(std::pair<std::string, double> stock_update) override;
    void subscribe(const std::string& stock) override;
    void unsubscribe(const std::string& stock) override;
};
