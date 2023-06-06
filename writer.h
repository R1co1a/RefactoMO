#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"

class writer {
    public:
        virtual void write(const storage_type& storage);
};

class text_writer : public writer {
    public: 
        text_writer();
        ~text_writer();
        void write(const storage_type& storage);
};

class binary_writer : public writer {
    public: 
        binary_writer();
        ~binary_writer();
        void write(const storage_type& storage);
};

#endif //WRITER_H