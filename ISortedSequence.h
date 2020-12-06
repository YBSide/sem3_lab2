#pragma once

#include "ListSequence.h"
#include "MergeSort.h"
#include <iostream>
#include "ArraySequence.h"

using namespace std;

int cmp(int a, int b) {
    return a > b;
}
template <typename T>
class sorted_sequence {
private:
    array_sequence<T>* data;
public:
    sorted_sequence(T* items, int size) {
        data = new array_sequence<T>(items, size);
        merge_sort(data, cmp);
    }

    sorted_sequence() {
        this->data = new array_sequence<T>();
    }

public:
    int get_size() {
        return data->get_length();
    }

    void add(T element) {
        data->append(element);
        merge_sort(data, cmp);
    }

    void remove(int index) {
        data->remove_at(index);
        merge_sort(data, cmp);
    }

    void show() {
        for(int i; i<data->get_length(); i++)
            cout << data->get(i);
    }
};
