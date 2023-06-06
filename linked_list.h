#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

class list_element {
    double _value;
    list_element *_prev;
    list_element *_next;

    public:
        list_element(double value=0.0, list_element *previous=nullptr, list_element *next=nullptr):
            _value(value), _prev(previous), _next(next) {}
        ~list_element() {}

        list_element *get_next() {return _next;}
        void set_next(list_element *next) {_next = next;}
        list_element *get_prev() {return _prev;}
        void set_prev(list_element *next) {_prev = next;}
        double get_value()const {return _value;}
        void set_value(double value){_value = value;}
};

class linked_list {
    list_element *_head;
    list_element *_tail;

    class iterator {
        private:
            list_element *current_element;
        public: 
            iterator(list_element *element) : current_element(element) {}
            iterator& operator++();
    };

    public: 
        linked_list(): _head(nullptr), _tail(nullptr) {}
        linked_list(const linked_list &other);
        ~linked_list() {clear();}
        linked_list &operator=(const linked_list &other);

        void clear();
        void push_back(double value); // Always add at the end
        void pop_element(); // Remove last element
        size_t size()const;
        double get_value(size_t index)const;

        void sort_list(bool ascending);

        double operator[](size_t index)const;

        iterator begin();
        iterator end();

};



#endif //LINKED_LIST_H