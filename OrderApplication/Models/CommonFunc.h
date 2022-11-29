//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_COMMONFUNC_H
#define ORDERAPPLICATION_COMMONFUNC_H

#include <string>
#include <iostream>

std::string ConvLower(std::string);
void Print(const std::string&);
void Print(long int);

template <typename Type>
/**
 * Gets an input from the user.
 * @param prompt What to ask the user. NOTE: does not append a new line at the end of the prompt
 * @return Type
 */
Type get_input(const std::string& prompt) {
    std::cout << prompt;
    Type input;
    std::getline(std::cin, input);
    return input;
}

/**
 * Returns a bool given the user response.
 * @param prompt What to ask the user.
 * @return Bool.
 */
bool get_bool(const std::string& prompt) {
    std::vector<std::string> yes = {
            "yes", "y", "t"
    };
    std::vector<std::string> no = {
            "no", "n", "f"
    };
    std::cout << prompt;
    std::string input = ConvLower(get_input<std::string>(""));
    while (true) {
        if (std::find(yes.begin(), yes.end(), input) != yes.end()) {
            // Checks if it's a yes value.
            return true;
        } else if (std::find(no.begin(), no.end(), input) != no.end()) {
            // Checks if it's a no value.
            return false;
        }
        input = ConvLower(get_input<std::string>("Accepts yes or no.\n"));
    }
}

void Print(const std::string& output) {
    std::cout << output;
}/*
void Print(unsigned long int output) {
    std::cout << output;
}*/
void Print(long int output) {
    std::cout << output;
}/*
void Print(double output) {
    std::cout << output;
}
void Print(char output) {
    std::cout << output;
}*/

std::string ConvLower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}
std::string ConvUpper(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

int get_from_list(const std::string& prompt, const std::vector<std::string>& list) {
    Print(prompt);
    for (const auto & i : list) {
        Print(" - " + i + "\n");
    }

    std::string input;
    input = ConvLower(get_input<std::string>(""));
    while (true) {
        for (int i = 0; i < list.size(); i++) {
            if (input == ConvLower(list[i])) {
                return i;
            }
        }
        input = ConvLower(get_input<std::string>("Pick from the list.\n"));
    }
}

#endif //ORDERAPPLICATION_COMMONFUNC_H
