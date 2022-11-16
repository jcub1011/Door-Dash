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

class FileReader {
private:
    std::string _contents;
public:
    /**
     * Opens the given file and stores the contents.
     * @param file_name The path of the file from the current folder.
     */
    explicit FileReader(const std::string& file_name) {
        std::ifstream file(file_name);

        if (file.is_open()) {
            std::string temp_line;
            while (file.good()) {
                std::getline(file, temp_line);
                _contents += temp_line + "\n";
            }
        }

        file.close();
    }

    /**
     * Gets the contents of the file.
     * @return The contents of the file.
     */
    std::string get_contents() {
        return _contents;
    }
};
