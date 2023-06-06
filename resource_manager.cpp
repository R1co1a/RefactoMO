#include "resource_manager.h"
#include "storage_type.h"

resource_manager::resource_manager(){};

resource_manager::~resource_manager(){
    clear_resources();
}

storage_type* resource_manager::make_storage(const std::string& type){
    
    if (storageMap.find(type) != storageMap.end()) {
        std::cout << "Using existing " << type << " storage" << std::endl;
        return storageMap[type];
    }
    
    storage_type* storage = nullptr;

    if (type == "LIST") {
        //storage = new list_storage();
    } else if (type == "VECTOR" ) {
        //storage = new vector_storage();
    } else {
        std::cout << "Unknown storage type: " << type << std::endl;
    }

    if (storage) {
        storageMap[type] = storage;
        std::cout << "Created " << type << " storage" << std::endl;
    }
    return storage;
}

loader* resource_manager::make_loader(const std::string& type){

    if (loaderMap.find(type) != loaderMap.end()) {
        std::cout << "Using existing " << type << " loader" << std::endl;
        return loaderMap[type];
    }

    loader* loader = nullptr;
    if (type == "BIN") {
        //loader = new binary_loader();
    } else if (type == "TEXT") {
        //loader = new text_loader();
    } else {
        std::cout << "Unknown loader type: " << type << std::endl;
    }
    
    if (loader) {
        loaderMap[type] = loader;
        std::cout << "Created " << type << " loader" << std::endl;
    }

    return loader;
}

calculation* resource_manager::make_calculation(const std::string& type){
    
    if (calculationMap.find(type) != calculationMap.end()) {
        std::cout << "Using existing " << type << " calculation" << std::endl;
        return calculationMap[type];
    }
    
    calculation* calculation = nullptr;
    if (type == "AVG") {
        //calculation = new average_calculation();
    } else if (type == "ROLL") {
        //calculation = new rolling_average_calculation();
    } else {
        std::cout << "Unknown calculation type: " << type << std::endl;
    }

    if (calculation) {
        calculationMap[type] = calculation;
        std::cout << "Created " << type << " calculation" << std::endl;
    }

    return calculation;
}

writer* resource_manager::make_writer(const std::string& type) {

    if (writerMap.find(type) != writerMap.end()) {
        std::cout << "Using existing " << type << " writer" << std::endl;
        return writerMap[type];
    }

    writer* writer = nullptr;
    if (type == "BIN") {
        //writer = new binary_writer();
    } else if (type == "TEXT") {
        //writer = new text_writer();
    } else {
        std::cout << "Unknown writer type: " << type << std::endl;
    }

    if (writer) {
        writerMap[type] = writer;
        std::cout << "Created " << type << " writer" << std::endl;
    }

    return writer;
}

void resource_manager::clear_resources() {

    for (auto& entry : storageMap){
        delete entry.second;
    }
    storageMap.clear();

    for (auto& entry : loaderMap){
        delete entry.second;
    }
    loaderMap.clear();

    for (auto& entry : calculationMap){
        delete entry.second;
    }
    calculationMap.clear();

    for (auto& entry : writerMap){
        delete entry.second;
    }
    writerMap.clear();
}