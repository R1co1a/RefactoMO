#include "loader.h"
#include <fstream>
#include <array>


storage_type text_loader::load (const std::string& filePath){
    storage_type storage;
    std::ifstream file{filePath};
    if (file.is_open()) {
        std::array<char, 100> buffer;
        while (file.getline(&buffer[0], 100)) {
            storage.push_back(std::stold(std::string{buffer.data()}));
        }
    } else {
        throw std::ios_base::failure("File cannot be opened for reading");
    }
    return storage;
}

storage_type binary_loader::load (const std::string& filePath){
    storage_type storage;

    std::ifstream file{filePath};
    if (file.is_open()) {
        double buffer;
        while (file.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            storage.push_back(buffer);
        }
    } else {
        throw std::ios_base::failure("File cannot be opened for reading");
    }
    return storage;
}