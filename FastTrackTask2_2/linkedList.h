//
// Created by Sofia on 20.04.2024.
//

#ifndef FASTTRACKTELECOM_LINKEDLIST_H
#define FASTTRACKTELECOM_LINKEDLIST_H

template <class T>
class node{
public:
    node(node *next, T data) : next(next), data(data) {}
    node * next;
    T data;
};

template <class T>
class linkedList {
private:
    node<T> head;
public:
    explicit linkedList(T data);

    void insertElement(T param); //inserts in the front of linkedlist
    bool deleteElement(T param);
    int findElement(T param); //returns index
    void print();
};

#endif //FASTTRACKTELECOM_LINKEDLIST_H
