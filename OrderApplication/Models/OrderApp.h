//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_ORDERAPP_H
#define ORDERAPPLICATION_ORDERAPP_H

#include <vector>
#include <string>
#include "Order.h"
#include "Restaurant.h"

class OrderApp {
private:
    std::vector<Restaurant> restaurants;
    std::vector<Order> orders;
public:
    OrderApp() {
        //TODO: Create generator for orderapp.
    }
    void display_restaurants() {
        //TODO: Implement method to print restaurants to the console.
    }
};

#endif //ORDERAPPLICATION_ORDERAPP_H
