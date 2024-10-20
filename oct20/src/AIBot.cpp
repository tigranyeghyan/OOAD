#include "../hpp/AIBot.hpp"
#include "../hpp/Observer.hpp"
#include "../hpp/StockExchange.hpp"
#include <iostream>

AIBot::AIBot(const std::string& name) : Observer(name)
{
}

void AIBot::update(std::pair<std::string, double> stock_update)
{
    std::cout << name << " --> " << stock_update.first << " " << stock_update.second << std::endl; 
}

void AIBot::subscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> addSubscriber(this, stock);
}

void AIBot::unsubscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> removeSubscriber(this, stock);
}
