//
// Created by Софья on 26.04.2024.
//

//Разработайте программу, демонстрирующую создание двух потоков в C++,
//где один поток пишет данные в переменную, а другой читает из нее, с использованием
//    мьютексов для синхронизации доступа.

#include <iostream>
#include <thread>
#include <mutex>

int value = 0;
std::mutex mutex;

void readValue(int& v) {
    mutex.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    v = value;
    mutex.unlock();
}

void writeValue(int v) {
    mutex.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    value = v;
    mutex.unlock();
}

int main() {
    int read1;
    std::thread readThread(readValue, std::ref(read1));
    std::thread writeThread(writeValue, 1);

    readThread.join();
    writeThread.join();

    std::cout << read1 << "\n";
    std::cout << value << "\n";
}