//
// Created by Luis Cabrera on 11/9/22.
//

#ifndef SCHOOLPROJECT_RESTAURANT_H
#define SCHOOLPROJECT_RESTAURANT_H

#include <string>
#include <utility>
#include <vector>
#include "Menu.h"
#include "CommonFunc.h"

class Restaurant : public Menu {
private:
    std::string _name;
    std::string _address;
public:
    /**
     * Creates a restaurant.
     * @param name Name of the restaurant.
     * @param address Address of the restaurant.
     */
    Restaurant(std::string& name, std::string& address, const std::vector<Item>& items) {
        _name = name;
        _address = address;
        item_list = items;

        //print_menu();
    }
    //TODO: Implement restaurant methods.
    std::string getName() {
        return _name;
    }
    std::string getAddress() {
        return _address;
    }
};


#endif //SCHOOLPROJECT_RESTAURANT_H
