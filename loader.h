#ifndef LOADER_H
#define LOADER_H
#include <string>

#include "storage_type.h"

class loader {
    public:
        virtual storage_type load(const std::string& filePath);
};

class text_loader : public loader {
    public:
        text_loader(){};
        ~text_loader(){};
        storage_type load (const std::string& filePath) override;
};

class binary_loader : public loader {
    public:
        binary_loader(){};
        ~binary_loader(){};
        storage_type load (const std::string& filePath) override;
};

#endif //LOADER_H