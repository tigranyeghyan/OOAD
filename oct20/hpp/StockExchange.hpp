#pragma once 
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <memory>
#include "Observer.hpp"

class StockExchange
{
public:
    static StockExchange* createStockExchange();
    void exchange(const std::string& stock, double amount);
    void addSubscriber(Observer *ptr, const std::string& stock);
    void removeSubscriber(Observer *ptr, const std::string& stock);
    ~StockExchange() = default; 
private:
    StockExchange();
    void notify(const std::string& stock);
    static std::unique_ptr<StockExchange> objptr;
    std::multimap<std::string, Observer*> subscriberInterest;
    std::vector<std::pair<std::string, double>> stocks;
};

