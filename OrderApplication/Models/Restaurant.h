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
    Restaurant(std::string name, std::string address, const std::unordered_map<std::string, double>& items) {
        _name = std::move(name);
        _address = std::move(address);

        for (const auto& item : items) {
            // Iterates through the map and adds the items to the menu list.
            Item temp(item.first, item.second);
            item_list.push_back(temp);
        }
    }
};


#endif //SCHOOLPROJECT_RESTAURANT_H
