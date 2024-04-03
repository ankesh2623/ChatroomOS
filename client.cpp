// client.cpp

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Connect to server
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345); // Server port number
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr); // Server IP address

    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        std::cerr << "Error connecting to server\n";
        return 1;
    }

    std::cout << "Connected to server\n";

    // Close client socket
    close(client_socket);

    return 0;
}
