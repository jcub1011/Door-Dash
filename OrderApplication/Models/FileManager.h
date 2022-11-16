//
// Created by jcubm on 11/16/2022.
//

#ifndef ORDERAPPLICATION_FILEMANAGER_H
#define ORDERAPPLICATION_FILEMANAGER_H

#endif //ORDERAPPLICATION_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "Restaurant.h"

class FileReader {
private:
    nlohmann::json _contents;
public:
    /**
     * Opens the given file and stores the contents as a json.
     * @param file_name The path of the file from the current folder.
     */
    explicit FileReader(const std::string& file_name) {
        std::ifstream file(file_name);
        _contents = nlohmann::json::parse(file);
        file.close();
    }
    // TODO: Have it create a list of restaurants that it then returns.

};
