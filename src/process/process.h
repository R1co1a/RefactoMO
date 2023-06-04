#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"


class process {
    private:
        storage_type* _storage;
        loader* _loader;
        calculation* _calculation;
        writer* _writer;
    public:
        process(storage_type* storage, loader* loader, calculation* calculation, writer* writer);
        
        void execute(const std::string& filePath);
};