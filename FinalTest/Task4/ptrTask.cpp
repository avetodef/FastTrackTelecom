//
// Created by Софья on 26.04.2024.
//

//Массив int[10], взять указатель (тип можно варировать)
//на первый элемент и с помощью арифметики указателей вывести 4 элемент массива.
#include <iostream>

int ptrTask(){
    int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = myArray;
    int* ptr4 = ptr+3;
    int result = *ptr4;
    std::cout << "4 element is " << result << std::endl;
}

