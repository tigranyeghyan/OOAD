#include "../hpp/MobileApp.hpp"
#include "../hpp/Observer.hpp"
#include "../hpp/StockExchange.hpp"
#include <iostream>

MobileApp::MobileApp(const std::string& name) : Observer(name)
{
}

void MobileApp::update(std::pair<std::string, double> stock_update)
{
    std::cout << name << " --> " << stock_update.first << " " << stock_update.second << std::endl; 
}

void MobileApp::subscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> addSubscriber(this, stock);
}

void MobileApp::unsubscribe(const std::string& stock)
{
    StockExchange *ptr = StockExchange::createStockExchange();
    ptr -> removeSubscriber(this, stock);
}
