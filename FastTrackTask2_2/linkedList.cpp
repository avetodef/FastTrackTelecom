//
// Created by Sofia on 20.04.2024.
//

#include "linkedList.h"
#include <iostream>

template <class T>
void linkedList<T>::insertElement(T param){
    auto* newElement = new node<T>(this->head.next, param);
    this->head.next = newElement;
}

template <class T>
bool linkedList<T>::deleteElement(T param){
    node<T>* prev = &this->head;
    node<T>* current = prev->next;
    while(current != nullptr){
        if(current->data == param){
            std::cout <<"element to delete found" << std::endl;
            prev->next = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "no such element" << std::endl;
    return false;
}


template <class T>
int linkedList<T>::findElement(T param){
    int cnt = 0;
    node<T>* current = &this->head;
    while(current->next != nullptr){
        if(current->data == param){
            return cnt;
        }
        current = current->next;
        cnt += 1;
    }
    return -1;
}

template<class T>
void linkedList<T>::print(){
    node<T>* current = this->head.next;
    while(current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
