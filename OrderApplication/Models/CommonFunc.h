//
// Created by Jacob on 11/10/2022.
//

#ifndef ORDERAPPLICATION_COMMONFUNC_H
#define ORDERAPPLICATION_COMMONFUNC_H

#include <string>
#include <iostream>

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

void print(const std::string& output) {
    std::cout << output;
}
void print(unsigned long int output) {
    std::cout << output;
}
void print(long int output) {
    std::cout << output;
}
void print(double output) {
    std::cout << output;
}
void print(char output) {
    std::cout << output;
}

#endif //ORDERAPPLICATION_COMMONFUNC_H
