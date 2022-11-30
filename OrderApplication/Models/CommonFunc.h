//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_COMMONFUNC_H
#define ORDERAPPLICATION_COMMONFUNC_H

#include <string>
#include <iostream>
#include <iomanip>

std::string conv_lower(std::string input);
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
    std::string input = conv_lower(get_input<std::string>(""));
    while (true) {
        if (std::find(yes.begin(), yes.end(), input) != yes.end()) {
            // Checks if it's a yes value.
            return true;
        } else if (std::find(no.begin(), no.end(), input) != no.end()) {
            // Checks if it's a no value.
            return false;
        }
        input = conv_lower(get_input<std::string>("Accepts yes or no.\n"));
    }
}

/**
 * A wrapper function that prints the prompts
 * @param output the prompt that is output to the console
 */
void Print(const std::string& output) {
    std::cout << output;
}

/**
 * A wrapper function that prints the prices
 * @param output the prompt that is output to the console
 */
void Print(long int output) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << output;
}

/**
 * Converts string to all lower case
 * @param input the string input
 * @return a lower case version of the string
 */
std::string conv_lower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

/**
 * Converts string to all upper case
 * @param input the string input
 * @return a upper case version of the string
 */
std::string conv_upper(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

/**
 * Used to prompt user that a selection is to be made
 * @param prompt the prompt the user receives
 * @param list the list the user chooses from
 * @return the prompt the user interacts with
 */
int get_option_from_list(const std::string& prompt, const std::vector<std::string>& list) {
    Print(prompt);
    for (const auto & i : list) {
        Print(" - " + i + "\n");
    }

    std::string input;
    input = conv_lower(get_input<std::string>(""));
    while (true) {
        for (int i = 0; i < list.size(); i++) {
            if (input == conv_lower(list[i])) {
                return i;
            }
        }
        input = conv_lower(get_input<std::string>("Pick from the list.\n"));
    }
}

#endif //ORDERAPPLICATION_COMMONFUNC_H
