#include <iostream>
#include <map>
#include <string>
#include "../hpp/StockExchange.hpp"

std::unique_ptr<StockExchange> StockExchange::objptr = nullptr;

StockExchange* StockExchange::createStockExchange()
{
    if(!objptr)
    {
        StockExchange *ptr = new StockExchange();
        objptr.reset(ptr);
        ptr = nullptr;
    }
    return objptr.get();
}


StockExchange::StockExchange()
{
    stocks = {
        {"Apple", 145.30},
        {"Google", 2750.00},
        {"Amazon", 3405.80},
        {"Microsoft", 299.50},
        {"Tesla", 720.25},
        {"Meta", 355.50},
        {"Netflix", 590.10},
        {"NVIDIA", 220.30},
        {"Intel", 54.75},
        {"AMD", 102.15},
        {"IBM", 135.90},
        {"Adobe", 660.75},
        {"Oracle", 88.50}
    };
}


void StockExchange::notify(const std::string& stock)
{
    int stock_index = -1;
    for(int i = 0; i < stocks.size(); ++i)
    {
        if(stocks[i].first == stock)
        {
            stock_index = i;
            break;
        }
    }
    if(stock_index == -1)
    {
        return;
    }

    for(const auto& it : subscriberInterest)
    {
        if(it.first == stock)
        {
            it.second -> update(stocks[stock_index]); 
        }
    }
}

void StockExchange::exchange(const std::string& stock, double amount)
{
    for(int i = 0; i < stocks.size(); ++i)
    {
        if(stocks[i].first == stock)
        {
            stocks[i].second = amount;
            notify(stock);
            return;
        }
    }
}

void StockExchange::addSubscriber(Observer *ptr, const std::string& stock)
{
    for(int i = 0; i < stocks.size(); ++i)
    {
        if(stocks[i].first == stock)
        {
            subscriberInterest.insert({stock, ptr});
            return;
        }
    }
}

void StockExchange::removeSubscriber(Observer *ptr, const std::string& stock)
{
    for(auto it = subscriberInterest.begin(); it != subscriberInterest.end(); ++it)
    {
        if(it -> first == stock && it -> second == ptr)
        {
            subscriberInterest.erase(it);
            break;
        }
    }
}