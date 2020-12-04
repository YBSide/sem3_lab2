#pragma once

template <typename T>
class sequence {
public:
    virtual int get_length() const = 0;
    virtual T get_first() const = 0;
    virtual T get_last() const = 0;
    virtual T get(const int i) const = 0;
    virtual sequence<T>* get_subsequence(const int start, const int end) const = 0;
public:
    virtual void append(T value) = 0;
    virtual void prepend(T value) = 0;
    virtual void set(int index, T item) = 0;
    virtual void insert_at(const int index, T value) = 0;
    virtual void remove_at(const int index) = 0;
    virtual sequence<T>* concat(sequence<T>* other) = 0;
    virtual ~sequence() = default;
};
