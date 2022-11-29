//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_ORDERAPP_H
#define ORDERAPPLICATION_ORDERAPP_H

#include <vector>
#include <string>
#include "Order.h"
#include "Restaurant.h"
#include "Item.h"

class OrderApp {
private:
    std::vector<Restaurant> _restaurants;
    std::vector<std::string>* _orders = new std::vector<std::string>;
public:
    OrderApp() {
        std::vector<std::string> names = {
            "Shake Shack",
            "Bare Necessities",
            "Specialty Kitchen"
        };
        std::vector<std::string> addresses = {
            "Shake Dr.",
            "West Ln.",
            "First Right Rd."
        };
        std::vector<std::vector<Item>> Items;
        Items.push_back({
            Item("Burger", 6.00),
            Item("Fries", 2.00),
            Item("Shake", 3.00),
            Item("Soda", 2.50)
        });
        Items.push_back({
            Item("Tomato Soup", 5.00),
            Item("French Dip", 7.00),
            Item("Apple Pie", 5.00),
            Item("Chicken Fritters", 6.50)
        });
        Items.push_back({
            Item("Baked Potato", 4.00),
            Item("Chicken Pot Pie", 8.00),
            Item("Blooming Onion", 5.00),
            Item("Prime Rib", 16.00)
        });

        for (int i = 0; i < names.size(); i++) {
            _restaurants.emplace_back(names[i], addresses[i], Items[i]);
        }

        int input = 0;
        bool repeat = true;
        while (repeat) {
            input = get_from_list("Pick an option below:\n",
                                  {"New Order", "View Past Orders", "Quit"});
            switch (input) {
                case 0:
                    start_new_order();
                    break;
                case 1:
                    print_past();
                    break;
                default:
                    repeat = false;
                    break;
            }
        }
    }

    void start_new_order() {
        auto cur_order = new Order(_restaurants);
        auto receipt = cur_order->getReceipt();
        Print("Here's your receipt.\n");
        Print(receipt);
        Print("Thanks for using Order Application. We hope to see you again soon!\n");
        _orders->push_back(receipt);
    }

    void print_past() {
        for (int i = 0; i < _orders->size(); i++) {
            Print("\nOrder #" + std::to_string(i + 1) + "\n");
            Print(_orders->at(i) + "\n");
        }
    }
};

#endif //ORDERAPPLICATION_ORDERAPP_H
