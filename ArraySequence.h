#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include <functional>
#include <exception>

using namespace std;

struct my_exception1 : public exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "You can't use it there. Please use ListSequence";
    }
};

template <typename T>
class array_sequence: public sequence<T> {
private:
    dynamic_array<T>* items;
public:
    array_sequence(T* items, int size) {
        this->items = new dynamic_array<T>(items, size);
    }
    array_sequence() {
        this->items = new dynamic_array<T>();
    }

public:
    int get_length() const override {
        return this->items->get_size();
    }

    T get_first() const override {
        return this->items->get(0);
    }

    T get_last() const override {
        return this->items->get(this->items->get_size() - 1);
    }

    T get(const int index) const override {
        return this->items->get(index);
    }

    array_sequence<T>* get_subsequence(const int start, const int end) const override {
        T arr[end-start+1];
        int j=0;
        for (int i=start; i<=end; ++i) {
            arr[j] = this->items->get(i);
            j++;
        }

        auto *subsequence = new array_sequence(arr, end-start+1);

        return subsequence;
    }

public:
    void append(T item) override {
        this->items->resize(this->items->get_size() + 1);
        this->items->set(item, this->items->get_size() - 1);
    }

    void prepend(T item) override {
        this->items->resize(this->items->get_size() + 1);
        T t1 = this->items->get(0);
        T t2;
        for(int i = 0; i < this->items->get_size() - 1; i++){
            t2 = t1;
            t1 = this->items->get(i + 1);
            this->items->set(t2, i + 1);
        }
        this->items->set(item, 0);

    }

    void insert_at(const int index, T value) override {

        this->items->resize(this->items->get_size() + 1);
        T t1 = this->items->get(index);
        T t2;
        for(int i = index; i < this->items->get_size() - 1; i++){
            t2 = t1;
            t1 = this->items->get(i + 1);
            this->items->set(t2, i + 1);
        }
        this->items->set(value, index);
    }

    void set(int index, T item) override {
        this->items->set(index, item);
    }

    void remove_at(const int index) override {
        throw my_exception1();
    }

    array_sequence<T>* concat(sequence<T>* other) override {
        throw my_exception1();
    }

    ~array_sequence(){
        delete this->items;
    }
};
