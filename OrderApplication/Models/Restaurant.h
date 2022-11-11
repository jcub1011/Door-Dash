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
    Menu* _menu;
public:
    /**
     * Creates a restaurant.
     * @param name Name of the restaurant.
     * @param address Address of the restaurant.
     * @param menu memory address for the menu.
     */
    Restaurant(std::string name, std::string address, Menu* menu) {
        _name = std::move(name);
        _address = std::move(address);
        _menu = menu;
    }

    void print_menu() {
        for (auto element : *_menu) {

        }
    }
};


#endif //SCHOOLPROJECT_RESTAURANT_H
