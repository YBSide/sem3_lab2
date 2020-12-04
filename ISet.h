#pragma once

#include "Sequence.h"
#include <exception>
#include <iostream>
#include "ListSequence.h"
using namespace std;

template <typename T>
class set {
protected:
     list_sequence<T>* data;

public:
    set() {
        data = new list_sequence<T>();
    }

public:
    int size() {
        return data->get_length();
    }

    void append(T element) {
        for (int i = 0; i < data->get_length(); i++) {
            if (element == data->get(i))
                return;
        }
        data->append(element);
    }

    void remove(T element) {
        for (int i = 0; i < data->get_length(); i++) {
            if (element == data->get(i)) {
                data->remove_at(i);
                return;
            }
        }
    }

    T get(T element) {
        for (int i = 0; i < data->get_length(); i++) {
            if (element == data->get(i))
                return data->get(i);
        }
        throw my_exception();
    }

    bool find(T element) {
        for (int i = 0; i < data->get_length(); i++) {
            if (element == data->get(i))
                return true;
        }
        return false;
    }

    void add(set<T> another_set) {
        for (int i = 0; i<another_set.size(); i++) {
            if (!find(another_set.data->get(i)))
                data->append(another_set.data->get(i));
        }
    }

    set<T> multiply(set<T> another_set) {
        set<T> tmp;
        for (int i = 0; i<this->size(); i++) {
            if (another_set.find(this->data->get(i))) {
                tmp.append(this->data->get(i));
            }
        }
        return tmp;
    }

    set<T> subtraction(set<T> another_set) {
        set<T> tmp;
        for (int i = 0; i<this->size(); i++) {
            if (!another_set.find(this->data->get(i))) {
                tmp.append(this->data->get(i));
            }
        }
        return tmp;
    }
    void show() {
        for (int i = 0; i < data->get_length(); i++) {
            cout << data->get(i) << endl;
        }
    }

};