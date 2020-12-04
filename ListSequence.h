#pragma once
#include "Sequence.h"
#include "LinkedList.h"

using namespace std;

template <typename T>
class list_sequence: public sequence<T> {
private:
    linked_list<T>* items;
public:
    list_sequence(T* items, int size) {
        this->items = new linked_list<T>(items, size);
    }
    list_sequence(linked_list<T>* items) {
        this->items = items;
    }

    list_sequence() {
        this->items = new linked_list<T>();
    }

public:
    int get_length() const override {
        return this->items->get_length();
    }

    T get_first() const override {
        return this->items->get_first();
    }

    T get_last() const override {
        return this->items->get_last();
    }

    T get(const int index) const override {
        return this->items->get(index);
    }

    list_sequence<T>* get_subsequence(const int start, const int end) const override {
        auto new_subsequence = new list_sequence(this->items->get_sub_list(start, end));
        return new_subsequence;
    }

public:
    void append(T item) override {
        return this->items->append(item);
    }

    void prepend(T item) override {
        return this->items->prepend(item);
    }

    void insert_at(const int index, T value) override {
        return this->items->insert_at(value, index);
    }

    void remove_at(const int index) override {
        this->items->remove_at(index);
    }

    void set(int index, T item) override {
        this->items->set(index, item);
    }

    list_sequence<T>* concat(sequence<T>* other) override {
        auto *combined_list = new linked_list<T>();

        for(int i = 0; i < other->get_length(); i++)
            combined_list->append(other->get(i));
        for(int j = 0; j < this->items->get_length(); j++)
            combined_list->append(this->get(j));
        auto *combined_sequence = new list_sequence(combined_list);
        return combined_sequence;
    }

    ~list_sequence() {
        delete this->items;
    }
};
