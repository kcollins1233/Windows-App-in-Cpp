#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <ws2tcpip.h>
#include <iostream>
#include <io.h>



#define PORT 8080

int start()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address 
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request 
    connect(clientSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress));

    // sending data 
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);

    // closing socket 
    close(clientSocket);

    return 0;
}
