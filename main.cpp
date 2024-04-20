//
// Created by Софья on 20.04.2024.
//
#include "FastTrackTask2_2/linkedList.h"|
#include <iostream>

int main(){
    linkedList<int> myLinkedList = linkedList(0);

    myLinkedList.insertElement(1);
    myLinkedList.insertElement(2);
    myLinkedList.insertElement(3);
    myLinkedList.insertElement(4);
    myLinkedList.insertElement(5);

    myLinkedList.print();

    int indx = myLinkedList.findElement(2);
    std::cout << "element "<< 2 << " is at index " << indx << std::endl;

    std::cout << "deleting 3 "<< std::endl;
    myLinkedList.deleteElement(3);
    myLinkedList.print();

    return 0;
}
