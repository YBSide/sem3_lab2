#pragma once

#include <iostream>
#include <exception>
using namespace std;

struct my_exception : public exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "Element doesn't exist";
    }
};

template <typename Tkey, typename Tvalue>
class dict {

    struct element_in_hash {
        Tkey key;
        Tvalue symbol;
        bool availability = false;
    };

private:
    element_in_hash* hash_arr;
    int count = 0;
    int capacity;

public:
    explicit dict(int size) {
        hash_arr = new element_in_hash[size];
        capacity = size;
    }

    dict() {
        hash_arr = new element_in_hash[40];
        capacity = 40;
    }

public:
    int return_hash(string data) {
        unsigned long hash = 5381;
        for (char i : data)
            hash = 33 * hash + (unsigned char)i;
        return hash % capacity;
    }

    void add(Tkey key, Tvalue value) {
        hash_arr[return_hash(key)].key = key;
        hash_arr[return_hash(key)].availability = true;
        hash_arr[return_hash(key)].symbol = value;
        count++;
    }

    int get_count() {
        return count;
    }

    int get_capacity() {
        return capacity;
    }

    Tvalue get(Tkey key) {
        if (!hash_arr[return_hash(key)].availability)
            throw my_exception();
        return hash_arr[return_hash(key)].symbol;
    }

    bool contains_key(Tkey key) {
        return hash_arr[return_hash(key)].availability;
    }

    void remove(Tkey key) {
        if (!hash_arr[return_hash(key)].availability)
            throw my_exception();
        hash_arr[return_hash(key)].availability = false;
        count--;
    }



};

