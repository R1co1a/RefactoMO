#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <unordered_map>

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class resource_manager {
    
    private: 
        std::unordered_map<std::string, storage_type*> storageMap;
        std::unordered_map<std::string, loader*> loaderMap;
        std::unordered_map<std::string, calculation*> calculationMap;
        std::unordered_map<std::string, writer*> writerMap;

    public : 
        resource_manager();

        ~resource_manager();

        storage_type* make_storage(const std::string& type);
        loader* make_loader(const std::string& type);
        calculation* make_calculation(const std::string& type);
        writer* make_writer(const std::string& type);

        void clear_resources();
};
#endif //RESOURCE_MANAGER_H