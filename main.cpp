#include "resource_manager.h"
#include "process.h"

int main() {
    
    resource_manager manager{};

    process process{manager.make_storage("LIST"),
                    manager.make_loader("BIN"), 
                    manager.make_calculation("AVG"), 
                    manager.make_writer("TEXT")};
    process.execute("../input/binary.bin");
    
    manager.clear_resources();
    
    return 0;
}
