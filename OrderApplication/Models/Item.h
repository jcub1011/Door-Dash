//
// Created by jcubm on 11/9/2022.
//

#ifndef ORDERAPPLICATION_ITEM_H
#define ORDERAPPLICATION_ITEM_H

#include <string>
#include <unordered_map>
#include <utility>


class Item {
private:
    std::string _name;
    double _cost = 0.0;
    std::unordered_map<std::string, double> _modifications;
public:
    /**
     * Sets the name and price of the item.
     * @param name Name of the item.
     * @param base_price The price without any modifications.
     */
    Item(std::string name, double base_price) {
        _name = std::move(name);
        _cost = base_price;
    }
    Item() = default;

    /**
     * Gets the name of the item.
     * @return std::string
     */
    std::string get_name() {
        // Gets the name of the item.
        return _name;
    }

    /**
     * Returns a map of the mods and their price modifiers.
     * @return unordered_map<std::string, double> {mod, price_modifier}
     */
    std::unordered_map<std::string, double> get_modifications() {
        return _modifications;
    }

    /**
     * Returns the price with the _modifications added on.
     * @return double
     */
    double get_price() {
        double tot_cost = _cost;
        for (const auto& element : _modifications) {
            tot_cost += element.second;
            // Second is the value in the key/value pair.
        }
        return tot_cost;
    }

    /**
     * Adds a modification to the modification map.
     * @param modification Name of the modification.
     * @param price_modifier By how much the price will increase.
     */
    void add_modification(const std::string& modification, double price_modifier) {
        _modifications[modification] = price_modifier;
    }

    /**
     * Deletes a modification from the modification map.\n
     * (safe)
     * @param mod Name of the modification.
     */
    void delete_modification(const std::string& mod) {
        if (_modifications.count(mod) > 0) {
            // Checks if the modification exists.
            _modifications.erase(mod);
        }
    }

    /**
     * Checks if a modification exists.
     * @param mod Name of the modification to check for.
     * @return Bool.
     */
    bool check_mod_exists(const std::string& mod) {
        return _modifications.count(mod);
    }

};


#endif //ORDERAPPLICATION_ITEM_H
