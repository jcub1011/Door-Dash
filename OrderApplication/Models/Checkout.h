//
// Created by Jacob on 11/28/2022.
//

#ifndef ORDERAPPLICATION_CHECKOUT_H
#define ORDERAPPLICATION_CHECKOUT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "CommonFunc.h"
#include "Order.h"
#include "Restaurant.h"
#include "Item.h"

#define TAX 0.065
#define DELIVERY_FEE 5.0

class Checkout {
private:
    std::vector<Item>* _items = new std::vector<Item>;
    std::string* _rest_name = new std::string;
    std::string* _buyer_name = new std::string;
    std::string* _receipt = new std::string;
public:
    /**
     * Prompts the user to proceed with checkout procedure.
     * @param list the list of food _items the user chose.
     * @param name the name given of the customer.
     */
    Checkout(std::vector<Item>& list, std::string& name) {
        *_buyer_name = get_input<std::string>("Enter your name:\n");
        *_rest_name = name;
        *_items = list;

        Print("Here's what we have you down for:\n");
        print_list();
        if (get_bool("Do you want to submit the order?\n")) {
            Print("Thank you!\n");
        } else {
            Print("Order canceled.\n");
            *_receipt = "+-----------------+\nOrder Canceled\n+-----------------+\n";
            _items->clear();
        }
    }

    /**
     * Prints the list of name and restaurant and any modifications requested
     * by the customer.
     */
    void print_list() {
        _receipt->clear();
        *_receipt += "+-----------------+\n";
        *_receipt += "Name: " + *_buyer_name + "\n";
        *_receipt += "Restaurant: " + *_rest_name + "\n";
        for (int i = 0; i < _items->size(); i++) {
            *_receipt += std::to_string(i + 1) + ". " + _items->at(i).get_name();
            // Print name
            *_receipt += " - $" + std::to_string(_items->at(i).get_price()) + "\n";
            // Print price.
            if (!_items->at(i).get_modifications().empty()) {
                *_receipt += "Modifications: \n";
                for (const auto& mod : _items->at(i).get_modifications()) {
                    *_receipt += " - " + mod.first + "\n";
                }
            }
        }
        *_receipt += "+-----------------+\n";
        Print(*_receipt);
    }

    /**
     * The user is able to get the _receipt at their request
     * @return a prompt with the _receipt and their taxes etc.
     */
    std::string get_receipt() {
        std::string temp = "Receipt\n";
        double price = 0.0;
        for (auto itm : *_items) {
            price += itm.get_price();
        }

        temp += *_receipt;
        temp += "Total: $" + std::to_string(price) + "\n";
        temp += "Tax: $" + std::to_string(price * TAX) + "\n";
        temp += "Delivery Fee: $" + std::to_string(DELIVERY_FEE) + "\n";
        temp += "Total Paid: $" + std::to_string(price * (1 + TAX) + DELIVERY_FEE) + "\n";
        temp += "+-----------------+\n";
        return temp;
    }
};

#endif //ORDERAPPLICATION_CHECKOUT_H
