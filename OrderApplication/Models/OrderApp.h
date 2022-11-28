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
    std::vector<Order>* _orders = new std::vector<Order>;
public:
    OrderApp() {
        std::vector<std::string> names = {
            "Restaurant 1",
            "Restaurant 2",
            "Restaurant 3"
        };
        std::vector<std::string> addresses = {
            "address 1",
            "address 2",
            "address 3"
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

        start_order();
    }
    void display_restaurants() {
        //TODO: Implement method to print restaurants to the console.
    }

    void start_order() {
        auto cur_order = new Order(_restaurants);
    }
};

#endif //ORDERAPPLICATION_ORDERAPP_H
