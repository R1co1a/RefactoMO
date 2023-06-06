#include <iostream>

#include "process.h"

process::process(storage_type* storage, loader* loader, calculation* calculation, writer* writer) 
    : _storage(storage), _loader(loader), _calculation(calculation), _writer(writer) {}

void process::execute(const std::string& filePath) {
    if (_storage && _loader && _calculation && _writer) {
        *_storage = _loader->load(filePath);
        //_calculation->compute(*_storage);
        _writer->write(*_storage);
    } else {
        std::cout << "Missing required objects for execution!" << std::endl;
    }
}