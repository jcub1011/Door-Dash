//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_ORDER_H
#define ORDERAPPLICATION_ORDER_H

#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "CommonFunc.h"
#include "Order.h"
#include "Restaurant.h"
#include "Item.h"

class Order {
private:
    std::vector<Item> item_list;
    Restaurant* _rest = nullptr;
    /**
     * Finds the index of the given name in the list. Returns -1 if not found.
     * @param restaurants List of restaurants.
     * @param name Name of the restaurant to find.
     * @return Index.
     */
    int nameInList(std::vector<Restaurant>& restaurants, std::string name) {
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        // Converts the string to lowercase.
        for (int i = 0; i < restaurants.size(); i++) {
            auto temp = restaurants[i].getName();
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

            if (name == temp) {
                return i;
            }
        }
        return -1;
    }

    void getOrder() {
        _rest->print_menu();

        Print("Pick an item to add to your cart.\n");
    }

    void addItem();

public:
    Order(std::vector<Restaurant>& restaurants) {
        auto name = new std::string;
        auto restaurant = new std::string;

        Print("Here's a list of available restaurants: \n");
        for (auto place : restaurants) {
            Print(place.getName() + "\n");
        }

        int response = nameInList(restaurants, *restaurant);
        while (response == -1) {
            // Checks if the name is a restaurant.
            *restaurant = get_input<std::string>("What restaurant would you like to order from?\n");
            response = nameInList(restaurants, *restaurant);
        }
        _rest = &restaurants[response];
        getOrder();
    }
};

#endif //ORDERAPPLICATION_ORDER_H
