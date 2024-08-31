#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <sstream>
#include <cctype>

#pragma comment(lib, "Ws2_32.lib")

std::string GetHttpResponse(const std::string& host, const std::string& path) {
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL;
    struct addrinfo hints;
    std::string response;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return "";
    }

    // Resolve the server address and port
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host.c_str(), "80", &hints, &result) != 0) {
        std::cerr << "getaddrinfo failed" << std::endl;
        WSACleanup();
        return "";
    }

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "socket failed" << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        return "";
    }

    // Connect to server
    if (connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "Unable to connect to server!" << std::endl;
        WSACleanup();
        return "";
    }

    // Send an HTTP GET request
    std::string request = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\nConnection: close\r\n\r\n";
    int bytesSent = send(ConnectSocket, request.c_str(), (int)request.length(), 0);
    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Send failed" << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return "";
    }

    // Receive response
    char recvbuf[4096];
    int bytesReceived;
    while ((bytesReceived = recv(ConnectSocket, recvbuf, sizeof(recvbuf) - 1, 0)) > 0) {
        recvbuf[bytesReceived] = '\0'; // Null-terminate the received data
        response += recvbuf;
    }

    if (bytesReceived == SOCKET_ERROR) {
        std::cerr << "Receive failed" << std::endl;
    }

    // Cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return response;
}

std::string ExtractJsonBody(const std::string& response) {
    size_t pos = response.find("\r\n\r\n");
    if (pos != std::string::npos) {
        return response.substr(pos + 4);
    }
    return "";
}

std::string ParseJsonForVersion(const std::string& json) {
    size_t pos = json.find("\"tag_name\"");
    if (pos == std::string::npos) {
        return "";
    }
    
    pos = json.find(":", pos);
    if (pos == std::string::npos) {
        return "";
    }

    pos = json.find_first_not_of(" \t\"", pos);
    if (pos == std::string::npos) {
        return "";
    }

    size_t endPos = json.find_first_of("\"", pos);
    if (endPos == std::string::npos) {
        return "";
    }

    return json.substr(pos, endPos - pos);
}

int main() {
    std::string host = "api.github.com";
    std::string path = "/repos/Lisu-Liso/GXCC/releases/latest";

    std::string response = GetHttpResponse(host, path);
    std::cout<<response<<std::endl;
    if (response.empty()) {
        std::cerr << "Failed to get HTTP response" << std::endl;
        return 1;
    }

    std::string jsonPart = ExtractJsonBody(response);
    if (jsonPart.empty()) {
        std::cerr << "Invalid response format" << std::endl;
        return 1;
    }

    std::string latestVersion = ParseJsonForVersion(jsonPart);
    if (latestVersion.empty()) {
        std::cerr << "Failed to parse JSON for version" << std::endl;
        return 1;
    }

    std::cout << "Latest version: " << latestVersion << std::endl;
    return 0;
}
