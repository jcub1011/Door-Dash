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
#include "Item.h"

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
    /**
     * Gets the index of the item in the item list.
     * @param item The name of the item to find.
     * @return Int, -1 if item doesn't exist.
     */
    int getItemIndex(std::string& item) {
        for (int i = 0; i < item_list.size(); i++) {
            if (ConvLower(item) == ConvLower(item_list[i].get_name())) {
                return i;
            }
        }
        return -1;
    }
    Item getItem(int index) {
        return item_list[index];
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
