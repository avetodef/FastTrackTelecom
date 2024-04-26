//
// Created by Софья on 26.04.2024.
//
#include <winsock2.h>
#include <iostream>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    const char* serverAddress = "localhost";
    try {

        // Initialize Winsock
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            throw std::runtime_error("WSAStartup failed");
        }

        // Create a socket
        SOCKET connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (connectSocket == INVALID_SOCKET) {
            throw std::runtime_error("Failed to create socket");
        }

        // Define server address
        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(serverAddress);
        serverAddr.sin_port = htons(PORT);

        // Connect to the server
        result = connect(connectSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
        if (result == SOCKET_ERROR) {
            throw std::runtime_error("Failed to connect to server");
        }

        std::cout << "Connected to server at " << serverAddress << std::endl;

        char buffer[BUFFER_SIZE];
        std::string message;

        // Send and receive messages
        while (true) {
            std::cout << "Введите сообщение: ";
            std::getline(std::cin, message);

            // Send message to the server
            int bytesSent = send(connectSocket, message.c_str(), message.size(), 0);
            if (bytesSent == SOCKET_ERROR) {
                throw std::runtime_error("Failed to send message");
            }

            // Receive response from the server
            int bytesReceived = recv(connectSocket, buffer, BUFFER_SIZE, 0);
            if (bytesReceived == SOCKET_ERROR) {
                throw std::runtime_error("Failed to receive response");
            }

            if (bytesReceived == 0) {
                std::cout << "Сервер закрыл соединение." << std::endl;
                break;
            }

            std::cout << "Сервер: " << std::string(buffer, bytesReceived) << std::endl;
        }

        closesocket(connectSocket);
        WSACleanup();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
