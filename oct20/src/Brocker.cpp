#include "../hpp/Brocker.hpp"
#include "../hpp/Observer.hpp"
#include "../hpp/StockExchange.hpp"
#include <iostream>

Brocker::Brocker(const std::string& name) : Observer(name)
{
}

void Brocker::update(std::pair<std::string, double> stock_update)
{
    std::cout << name << " --> " << stock_update.first << " " << stock_update.second << std::endl; 
}

void Brocker::subscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> addSubscriber(this, stock);
}

void Brocker::unsubscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> removeSubscriber(this, stock);
}
