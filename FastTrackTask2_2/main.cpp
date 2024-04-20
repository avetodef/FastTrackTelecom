//
// Created by Софья on 20.04.2024.
//
#include "linkedList.h"|
#include <iostream>

int main(){
    linkedList<int> myLinkedList{};
    for (int i = 0; i < 10; i++){
        myLinkedList.insertElement(i);
    }

    myLinkedList.print();

    int indx = myLinkedList.findElement(2);
    std::cout << "element "<< 2 << " is at index " << indx << std::endl;

    std::cout << "deleting 3 "<< std::endl;
    myLinkedList.deleteElement(3);
    myLinkedList.print();

    std::cout <<"deleting last element " << std::endl;
    myLinkedList.deleteElement(0);
    myLinkedList.print();

    std::cout <<"deleting first element " << std::endl;
    myLinkedList.deleteElement(9);
    myLinkedList.print();

    std::cout <<"deleting nonexistent element " << std::endl;
    myLinkedList.deleteElement(1340);
    myLinkedList.print();

    std::cout <<"finding nonexistent element " << std::endl;
    indx = myLinkedList.findElement(2000);
    std::cout << "element "<< 2000 << " is at index " << indx << std::endl;

    return 0;
}
