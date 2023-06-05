#include "linked_list.h"

linked_list::linked_list(const linked_list &other) {
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

linked_list &linked_list::operator=(const linked_list &other) {
    clear();
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void linked_list::clear() {
    list_element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

void linked_list::push_back(double value) {
    if (!_head) {
        _head = new list_element(value);
        _tail = _head;
    } else {
        _tail->set_next(new list_element(value, _tail));
        _tail = _tail->get_next();
    }
}

void linked_list::pop_element() {
    if (_head) {
        list_element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}

size_t linked_list::size() const {
    size_t size = 0;
    list_element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++size;
    }
    return size;
}

double linked_list::get_value(size_t index) const {
    size_t pos = 0;
    list_element *ptr = _head;
    while (ptr) {
        if (pos == index)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    // Error case: position out of bounds
}

void linked_list::sort_list(bool ascending) { // Naive sort
    list_element *ptr = _head;
    while (ptr && ptr->get_next()) {
        list_element *min_element = ptr;
        list_element *cursor = ptr;
        while (cursor) {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}

linked_list::iterator linked_list::begin() {
    return iterator(_head);
}

linked_list::iterator linked_list::end() {
    return iterator(nullptr);
}

linked_list::iterator& linked_list::iterator::operator++() {
    current_element = current_element->get_next();
    return *this;
}

double linked_list::operator[](size_t index) const {
    return get_value(index);
}

