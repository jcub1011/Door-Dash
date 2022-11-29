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
        //std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        name = ConvLower(name);
        // Converts the string to lowercase.
        for (int i = 0; i < restaurants.size(); i++) {
            auto temp = ConvLower(restaurants[i].getName());

            if (name == temp) {
                return i;
            }
        }
        return -1;
    }

    void getOrder() {
        auto response = new std::string;
        _rest->print_menu();
        addItem();
    }

    Item addItem() {
        Item* temp_item = new Item;
        int response = -1;
        auto input = new std::string;

        while (response == -1) {
            *input = get_input<std::string>("Pick an item to add to your cart.\n");
            response = _rest->getItemIndex(*input);
        }
        *temp_item = _rest->getItem(response);
        Print("Please enter your modifications (enter finished to stop):\n");
        //temp_item->
    }

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
