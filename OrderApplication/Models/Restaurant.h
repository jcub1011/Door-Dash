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
public:
    /**
     * Creates a restaurant.
     * @param name Name of the restaurant.
     * @param address Address of the restaurant.
     */
    Restaurant(std::string& name, std::string& address, const std::vector<Item>& items) {
        _name = name;
        _item_list = items;
    }
    /**
     * Gets the index of the item in the item list.
     * @param item The name of the item to find.
     * @return Int, -1 if item doesn't exist.
     */
    int get_item_index(std::string& item) {
        for (int i = 0; i < _item_list.size(); i++) {
            if (conv_lower(item) == conv_lower(_item_list[i].get_name())) {
                return i;
            }
        }
        return -1;
    }
    Item get_item(int index) {
        return _item_list[index];
    }

    std::string get_name() {
        return _name;
    }
};


#endif //SCHOOLPROJECT_RESTAURANT_H
