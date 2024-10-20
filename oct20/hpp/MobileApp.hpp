#pragma once
#include "Observer.hpp"
#include <string>

class MobileApp : public Observer
{
public:
    MobileApp(const std::string& name);
    void update(std::pair<std::string, double> stock_update) override;
    void subscribe(const std::string& stock) override;
    void unsubscribe(const std::string& stock) override;
};
