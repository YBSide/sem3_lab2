#pragma once
#include "Sequence.h"

template <typename T>
sequence<T>* shell_sort(sequence<T>* arr) {
    for (int bias = arr->get_length()/2; bias > 0; bias /= 2) {

        for (int i = bias; i < arr->get_length(); i++) {

            T temp = arr->get(i);
            int j;
            j = i;
            while ((j >= bias) && (arr->get(j - bias).word > temp.word)) {
                arr->set(j, arr->get(j - bias));
                j -= bias;
            }
            arr->set(j, temp);
        }
    }
    return arr;
}