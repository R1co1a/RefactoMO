#include <string>

#include "storage_type.h"

class loader {
    public:
        virtual ~loader();
        virtual storage_type load(const std::string& filePath);
};

class text_loader : public loader {
    public:
        storage_type load (const std::string& filePath) override;
};

class binary_loader : public loader {
    public:
        storage_type load (const std::string& filePath) override;
};