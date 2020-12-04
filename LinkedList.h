#pragma once

#include <cstddef>
#include <stdexcept>

using namespace std;

template <typename T>
class linked_list {
private:
    struct list_element {
        T data;
        list_element* next;
    };
    list_element *head, *tail;
    int size;
public:
    linked_list(T* items, int size) {
        int i = 0;

        this->size = size;

        this->head = new list_element;
        this->head->data = items[0];
        this->head->next = nullptr;
        this->tail = this->head;
        int j = i+1;
        for (j; j<size; j++) {
            auto tmp = new list_element;
            tmp->data = items[j];
            tmp->next = nullptr;
            this->tail->next = tmp;
            this->tail = this->tail->next;
        }
    }
    linked_list() {
        this->size = 0;
        this->head = nullptr;
        this->tail = this->head;
    }
    linked_list(const linked_list<T> &list) {
        list_element *tmp = list.head;
        this->size = list.size;
        while (tmp != nullptr) {
            prepend(tmp->data);
            tmp = tmp->next;
        }
    }

public:
    T get_first() {
        if (this->head == nullptr)
            throw out_of_range("First element is NULL");
        return this->head->data;
    }
    T get_last() {
        if (this->tail == nullptr)
            throw out_of_range("list's size = 1 and last element is NULL");
        return this->tail->data;
    }
    T get(int index) {
        if (index < 0 || index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");
        int i = 0;
        list_element *tmp = this->head;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        return tmp->data;
    }
    linked_list<T>* get_sub_list(int start_index, int end_index) {
        if (start_index < 0 || start_index >= this->size || end_index < 0 || end_index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");

        int new_size = end_index - start_index + 1;

        T elements[new_size];
        int j = 0;
        for (int i=start_index; i<=end_index; ++i) {
            elements[j] = this->get(i);
            j++;
        }

        auto new_list = new linked_list(elements, new_size);
        return new_list;
    }

    void set(const int index, const T value) {
        if (index < 0 || index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");
        int i = 0;
        auto tmp = head;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        tmp->data = value;
    }

    int get_length() {
        return this->size;
    }

public:
    void prepend(T item) {

        this->size += 1;

        auto *tmp = new list_element;
        tmp->data = item;
        tmp->next = nullptr;

        if (this->head == nullptr) {
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail->next = tmp;
            this->tail = this->tail->next;
        }
    }
    void append(T item) {
        this->size += 1;

        auto *tmp = new list_element;
        tmp->data = item;
        tmp->next = this->head;
        this->head = tmp;
    }
    void insert_at(T item, int index) {
        if (index<0 || index >= this->size)
            throw out_of_range("index out of range");

        list_element *tmp = this->head;
        list_element *pre_tmp = this->head;
        int i = 0;

        while(i != index) {
            i++;
            pre_tmp = tmp;
            tmp = tmp->next;
        }

        auto *new_element = new list_element;
        new_element->data = item;
        if (i != 0) {
            pre_tmp->next = new_element;
            new_element->next = tmp->next;
        }
        else {
            append(item);
            this->size -= 1;
        }
        this->size += 1;
    }

    void concat(linked_list<T> *list) {
        this->tail->next = list->head;
        this->tail = list->tail;
        this->size += list->size;
    }

    void remove_at(int index) {
        if (index<0 || index >= this->size)
            throw out_of_range("index out of range");

        list_element *tmp = this->head;
        list_element *pre_tmp = this->head;
        int i = 0;

        if (this->size == 0 && this->head == nullptr)
            return;

        if (this->size == 1 && this->head != nullptr) {
            delete this->head;
            this->head = nullptr;
            this->size -= 1;
            return;
        }

        if (index == 0) {
            tmp = this->head->next;
            delete this->head;
            this->head = tmp;
            this->size -= 1;
            return;
        }

        while(i != index) {
            i++;
            pre_tmp = tmp;
            tmp = tmp->next;
        }

        pre_tmp->next = tmp->next;
        delete tmp;
        size -= 1;
    }

    ~linked_list() {
        auto tmp = this->head;
        auto next = this->head;
        while (tmp != nullptr) {
            next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }
};