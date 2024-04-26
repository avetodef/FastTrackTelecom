#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32")
#define PORT 8080
#define BUFFER_SIZE 1024

//данное задание выполнено на WinSocket , так как во время написания теста мой ubuntu перестал работать,
int main() {
    try {
        // Initialize Winsock
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            throw std::runtime_error("WSAStartup failed");
        }

        SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (listenSocket == INVALID_SOCKET) {
            throw std::runtime_error("Failed to create socket");
        }

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(PORT);

        result = bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
        if (result == SOCKET_ERROR) {
            throw std::runtime_error("Failed to bind socket");
        }

        result = listen(listenSocket, 1);
        if (result == SOCKET_ERROR) {
            throw std::runtime_error("Failed to listen for connections");
        }

        std::cout << "Server listening on port " << PORT << std::endl;


        SOCKET clientSocket;
        sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);
        clientSocket = accept(listenSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
        if (clientSocket == INVALID_SOCKET) {
            throw std::runtime_error("Failed to accept connection");
        }

        char buffer[BUFFER_SIZE];
        int bytesReceived;

        while ((bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(clientSocket, buffer, bytesReceived, 0);

            std::cout << "Received: " << std::string(buffer, bytesReceived) << std::endl;
        }

        closesocket(clientSocket);
        closesocket(listenSocket);
        WSACleanup();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
