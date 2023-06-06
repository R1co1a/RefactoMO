#include <fstream>
#include <string>

#include "writer.h"

const std::string OUTPUT = "test";

text_writer::text_writer(){}
binary_writer::binary_writer(){}

void text_writer::write(const storage_type& storage){
    std::ofstream file{OUTPUT + ".txt"};
    if (file.is_open()){
        for (size_t i=0; i<storage.size(); i++) {
            file << storage.get_value(i) << std::endl;
        }
    } else {
        throw std::ios_base::failure("File cannot be opened for writing.");
    }
}

void binary_writer::write(const storage_type& storage){
    std::ofstream file{OUTPUT + ".bin", std::ios::binary};
    if (file.is_open()) {
        for (size_t i=0; i < storage.size(); i++) {
            double val = storage.get_value(i);
            file.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else {
        throw std::ios_base::failure("File cannot be opened for writing.");
    }
}