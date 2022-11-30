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
    std::vector<Item>* items = new std::vector<Item>;
    std::string* rest_name = new std::string;
    std::string* buyer_name = new std::string;
    std::string* receipt = new std::string;
public:
    Checkout(std::vector<Item>& list, std::string& name) {
        *buyer_name = get_input<std::string>("Enter your name:\n");
        *rest_name = name;
        *items = list;

        Print("Here's what we have you down for:\n");
        printList();
        if (get_bool("Do you want to submit the order?\n")) {
            Print("Thank you!\n");
        } else {
            Print("Order canceled.\n");
            *receipt = "+-----------------+\nOrder Canceled\n+-----------------+\n";
            items->clear();
        }
    }

    void printList() {
        receipt->clear();
        *receipt += "+-----------------+\n";
        *receipt += "Name: " + *buyer_name + "\n";
        *receipt += "Restaurant: " + *rest_name + "\n";
        for (int i = 0; i < items->size(); i++) {
            *receipt += std::to_string(i + 1) + ". " + items->at(i).get_name();
            // Print name
            *receipt += " - $" + std::to_string(items->at(i).get_price()) + "\n";
            // Print price.
            if (!items->at(i).get_modifications().empty()) {
                *receipt += "Modifications: \n";
                for (const auto& mod : items->at(i).get_modifications()) {
                    *receipt += " - " + mod.first + "\n";
                }
            }
        }
        *receipt += "+-----------------+\n";
        Print(*receipt);
    }

    std::string getReceipt() {
        std::string temp = "Receipt\n";
        double price = 0.0;
        for (auto itm : *items) {
            price += itm.get_price();
        }

        temp += *receipt;
        temp += "Total: $" + std::to_string(price) + "\n";
        temp += "Tax: $" + std::to_string(price * TAX) + "\n";
        temp += "Delivery Fee: $" + std::to_string(DELIVERY_FEE) + "\n";
        temp += "Total Paid: $" + std::to_string(price * (1 + TAX) + DELIVERY_FEE) + "\n";
        temp += "+-----------------+\n";
        return temp;
    }
};

#endif //ORDERAPPLICATION_CHECKOUT_H
