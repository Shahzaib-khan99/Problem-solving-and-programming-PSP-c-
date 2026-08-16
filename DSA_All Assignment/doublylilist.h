#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>

template <typename T>
struct dnode {
    T val;
    dnode<T>* next;
    dnode<T>* prev;
};

template <typename T>
class list {
private:
    dnode<T>* h;
    int n;

public:

    list();
    ~list();

    T& operator (const T& v);

    bool operator==(const list<T>& rhs);
    bool operator!=(const list<T>& rhs);
    bool operator<=(const list<T>& rhs);
    bool operator>=(const list<T>& rhs);
    bool operator>(const list<T>& rhs);
    bool operator<(const list<T>& rhs);

    class iterator {
    private:
        dnode<T>* ptr;

    public:
        T& operator*();
        T* operator->();

        bool operator==(const iterator& rhs) const;

        iterator& operator++();
        iterator operator++(int);

        iterator& operator--();
        iterator operator--(int);
    };

    iterator begin();
    iterator end();

    std::reverse_iterator<iterator> rbegin();
    std::reverse_iterator<iterator> rend();

    T& front();
    T& back();

    iterator insert(iterator pos, const T& v);
    iterator erase(iterator pos);

    void push_front(const T& v);
    void push_back(const T& v);

    void pop_front();
    void pop_back();

    int size() const;
    bool empty() const;

    void clear();
    void resize(int ns, const T& v = T());

    void merge(list<T>& other);
    void swap(list& other);

    void reverse();
    void sort();
    void unique();
};

#endif
