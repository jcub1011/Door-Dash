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
#include "Checkout.h"

class Order {
private:
    std::vector<Item> item_list;
    Restaurant* _rest = nullptr;
    std::string _receipt;
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
        bool response;
        _rest->print_menu();

        response = get_bool("Would you like to select an item from the menu?\n");
        while (response) {
            item_list.push_back(addItem());
            Print(item_list[0].get_name() + "\n");
            response = get_bool("Would you like to select another item?\n");
        }
    }

    /**
     * Gets an item the user selects from the menu with modifications.
     * @return Item.
     */
    Item addItem() {
        // Inits
        Item* temp_item = new Item;
        int response = -1;
        auto input = new std::string;

        while (response == -1) {
            *input = get_input<std::string>("Pick an item to add to your cart.\n");
            response = _rest->getItemIndex(*input);
        }

        *temp_item = _rest->getItem(response);
        Print("Please enter your modifications:\n");
        Print("(enter 'finished' to stop or enter modification name again to delete)\n");

        *input = ConvUpper(get_input<std::string>(""));
        while (*input != "FINISHED") {
            if (temp_item->check_mod_exists(*input)) {
                Print(*input + " deleted.\n");
                temp_item->delete_modification(*input);
            } else {
                Print(*input + " added.\n");
                temp_item->add_modification(*input, 0.0);
            }
            *input = ConvUpper(get_input<std::string>(""));
        }
        return *temp_item;
    }

public:
    Order(std::vector<Restaurant>& restaurants) {
        auto name = new std::string;
        auto restaurant = new std::string;

        Print("Here's a list of available restaurants: \n");
        for (auto place : restaurants) {
            Print(" - " + place.getName() + "\n");
        }

        int response = nameInList(restaurants, *restaurant);
        while (response == -1) {
            // Checks if the name is a restaurant.
            *restaurant = get_input<std::string>("What restaurant would you like to order from?\n");
            response = nameInList(restaurants, *restaurant);
        }

        _rest = &restaurants[response];
        getOrder();
        Print("Thank you! Taking you to your cart!\n");
        auto check = new Checkout(item_list, *restaurant);
        _receipt = check->getReceipt();
    }

    std::string getReceipt() {
        return _receipt;
    }
};

#endif //ORDERAPPLICATION_ORDER_H
