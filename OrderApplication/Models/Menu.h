//
// Created by Luis Cabrera on 11/9/22.
//

#ifndef SCHOOLPROJECT_MENU_H
#define SCHOOLPROJECT_MENU_H

#include <unordered_map>
#include <string>
#include <iostream>
#include "Item.h"
#include <vector>

class Menu {
private:
    std::vector<Item> item_list;
public:
    explicit Menu(const std::unordered_map<std::string, double>& items) {
        for (const auto& item : items) {
            // Iterates through the map and adds the items to the menu list.
            Item temp(item.first, item.second);
            item_list.push_back(temp);
        }
    }
};


#endif //SCHOOLPROJECT_MENU_H
