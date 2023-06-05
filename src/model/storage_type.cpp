#include "storage_type.h"

void list_storage::push_back(double value){
    _data.push_back(value);
}

void list_storage::clear_list(){
    _data.clear();
}

double list_storage::get_value(size_t index)const {
    return _data[index];
}

size_t list_storage::size()const {
    return _data.size();
}

void vector_storage::push_back(double value){
    _data.push_back(value);
}

void vector_storage::clear_list(){
    _data.clear();
}

double vector_storage::get_value(size_t index) const {
    return _data[index];
}

size_t vector_storage::size()const {
    return _data.size();
}