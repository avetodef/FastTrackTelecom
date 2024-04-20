//
// Created by Софья on 20.04.2024.
//

#include "linkedList.h"

template <class T>
void linkedList<T>::insertElement(T param){
    ::node<T> newElement = ::node<T>(this->node, param);
    *this = newElement;
}

template <class T>
bool linkedList<T>::deleteElement(T param){
    linkedList<T>* prev = head;
    linkedList<T>* current = head.next;
    while(current!= nullptr){
        if(current->data == param){
            break;
        }
        prev = current;
        current = current->next;
    }
    if(current == nullptr){
        return false; ///cannot delete nullptr
    }
    prev->next = current->next;
    delete current;
    return true;
}

template <class T>
T linkedList<T>::findElement(T param){
    while(this!= nullptr){
        if(this->data == param){
            return this->data;
        }
        this = this->next;
    }
    return nullptr;
}