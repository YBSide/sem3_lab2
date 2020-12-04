#pragma once
#include "Sequence.h"
#include "ArraySequence.h"
using namespace std;
template <typename T>
sequence<T>* merge(sequence<T>* arr, int left, int right, int middle) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    T L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr->get(left + i);
    for (j = 0; j < n2; j++)
        R[j] = arr->get(middle + 1 + j);

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr->set(k, L[i]);
            i++;
        }
        else {
            arr->set(k, R[j]);
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr->set(k, L[i]);
        i++;
        k++;
    }
    while (j < n2) {
        arr->set(k, R[j]);
        j++;
        k++;
    }
    return arr;
}
template <typename T>
void merge_sort_(sequence<T>* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort_(arr, left, middle);
        merge_sort_(arr, middle + 1, right);
        arr = merge(arr, left, right, middle);
    }
}
template <typename T>
sequence<T>* merge_sort(sequence<T>* arr, int (*cmp)(T, T)) {
    merge_sort_(arr, 0, arr->get_length() - 1);
    return arr;
}

