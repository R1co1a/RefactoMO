#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

#include <list>
#include <vector>
#include <cstddef>

#include "linked_list.h"

class storage_type {
    public:
        virtual void push_back(double value);
        virtual void clear_list();
        virtual double get_value(size_t index) const;
        virtual size_t size () const;
};

class list_storage : public storage_type {
    private:
        linked_list _data;
    public:
        list_storage(){};
        ~list_storage(){};
        void push_back(double value)override;
        void clear_list()override;
        double get_value(size_t index) const override;
        size_t size() const override;
};

class vector_storage : public storage_type{
    private:
        std::vector<double> _data;
    public:
        vector_storage(){};
        ~vector_storage(){};
        void push_back(double value)override;
        void clear_list()override;
        double get_value(size_t index) const override;
        size_t size() const override;
};

#endif //STORAGE_TYPE_H


