#include "storage_type.h"

class writer {
    public: 
        virtual ~writer();
        virtual void write(const storage_type& data);
};

class text_writer : public writer {
    public: 
        virtual void write(const storage_type& data);
};

class binary_writer : public writer {
    public: 
        virtual void write(const storage_type&data);
};