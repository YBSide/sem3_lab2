#pragma once
#include <stdexcept>

using namespace std;

template <typename T>
class dynamic_array {
private:
    T* items;
    bool* items_check{};
    int size;
public:
    dynamic_array(T* items, int size)
    {
        this->items = new T[size];
        this->items_check = new bool[size];
        this->size = size;

        for (int i = 0; i < size; ++i)
        {
            this->items_check[i] = true;
            this->items[i] = items[i];
        }
    }
    explicit dynamic_array(const int size)
    {
        if ( size < 0 )
            throw length_error("Wrong size");
        this->items = new T[size];
        this->items_check = new bool[size];
        for (int i = 0; i < size; i++)
            this->items_check[i] = false;
        this->size = size;
    }

    dynamic_array(const dynamic_array<T> &array)
    {
        dynamic_array(array.data, array.size);
    }

    dynamic_array() {
        this->size = 0;
        this->items = nullptr;
    }
public:
    [[nodiscard]] int get_size() const { return this->size; }
    T get(const int index) const
    {
        if (index < 0 || index >= this->size || !this->items_check[index])
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");
        return this->items[index];
    }
public:
    void set(const int index, const T value)
    {
        if (index < 0 || index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");
        this->items[index] = value;
        this->items_check[index] = true;
    }
    void resize(int new_size)
    {
        int previous_size = this->size;
        if (new_size >= previous_size)
        {
            T *new_items = new T[new_size];
            bool *new_items_check = new bool[new_size];
            for (int i = 0; i < previous_size; ++i)
            {
                new_items_check[i] = this->items_check[i];
                new_items[i] = this->items[i];

            }
            for (int i = previous_size; i < new_size; i++)
                new_items_check[i] = false;

            delete[] this->items_check;
            delete[] this->items;

            this->items_check = new_items_check;
            this->items = new_items;
        }

        this->size = new_size;
    }
    ~dynamic_array() {
        this->size = 0;
        delete[] this->items;
    }
};