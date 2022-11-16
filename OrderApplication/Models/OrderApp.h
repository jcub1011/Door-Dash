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
    std::vector<Restaurant> _restaurants;
    std::vector<Order> _orders;
public:
    OrderApp() {
        //TODO: Create generator for order app.
    }
    void display_restaurants() {
        //TODO: Implement method to print restaurants to the console.
    }
};

#endif //ORDERAPPLICATION_ORDERAPP_H
