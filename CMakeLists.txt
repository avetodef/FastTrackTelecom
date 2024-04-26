cmake_minimum_required(VERSION 3.23)
project(FastTrackTelecom)

set(CMAKE_CXX_STANDARD 20)

add_executable(FastTrackTelecom
        FastTrackTask2_2/linkedList.cpp
        FastTrackTask2_2/linkedList.h
        FastTrackTask2_2/task2_2_main.cpp
        FastTrackTask2_1/main.cpp FinalTest/Task4/ptrTask.cpp FinalTest/Task1/DBMS.cpp FinalTest/Task2/ReadWrite.cpp FinalTest/Task3/tcpserver.cpp FinalTest/Task3/client.cpp)


