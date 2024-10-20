#include <iostream>
#include "../hpp/StockExchange.hpp"
#include "../hpp/AIBot.hpp"
#include "../hpp/Brocker.hpp"
#include "../hpp/MobileApp.hpp"

/*
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
*/

int main()
{
    StockExchange *ptr = StockExchange::createStockExchange();
    AIBot bot("CHatGPT");
    MobileApp app("Binance");
    Brocker brocker("Tigran");

    bot.subscribe("Apple");
    app.subscribe("Apple");
    brocker.subscribe("Apple");

    ptr -> exchange("Apple", 500.0);
    
    bot.subscribe("AMD");
    app.subscribe("AMD");
    brocker.subscribe("Intel");

    ptr -> exchange("AMD", 500.0);
    ptr -> exchange("Intel", 500.0);

    brocker.unsubscribe("Intel");
    ptr -> exchange("Intel", 600.0);

    return 0;
}
