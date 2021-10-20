#include "spdlog/spdlog.h"
#include "ini/ini.hpp"
#include "server.hpp"

#include <sys/epoll.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <cstring>
#include <netdb.h>
#include <array>

server::server()
{
}

server::~server()
{
}

int server::start_server()
{
    spdlog::info("Welcome to cherokee!");
    spdlog::info("Loading config file...");

    //loading conf file

    // open fd
    try
    {
        bind_socket("10000");
    }
    catch(const std::runtime_error& e)
    {
        spdlog::critical("");
        exit(EXIT_FAILURE);
    }

    // start a define number of workers

    return 0;
}

int server::bind_socket(std::string const& port)
{
    struct addrinfo hints;
    int socketfd;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; // IPV4 / IPV6
    hints.ai_socktype = SOCK_STREAM; // TCP
    hints.ai_flags = AI_PASSIVE; // Server mode

    struct addrinfo* result;
    int sockt = getaddrinfo(nullptr, port.c_str(), &hints, &result);

    if (sockt != 0)
    {
        throw std::runtime_error("bind_socket");
    }

    socketfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socketfd == -1)
    {
        throw std::runtime_error("Failed to create socket.");
    }

    // sockt = bind(socketfd, rp->ai_addr, rp->ai_addrlen);
    // if (sockt == 0)
    // {
    //     break;
    // }

    close(socketfd);

    return 0;
}