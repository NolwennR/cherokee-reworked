#include "utils/spdlog/spdlog.h"
#include "utils/ini/ini.hpp"
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

Server::Server()
{
}

Server::~Server()
{
}

int Server::startServer()
{
    spdlog::info("Welcome to cherokee!");
    spdlog::info("Loading config file...");

    //loading conf file

    // open fd
    try
    {
        BindSocket("10000");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    // start a define number of workers

    return 0;
}

int Server::BindSocket(std::string const& port)
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
        spdlog::critical("getaddrinfo failed");
        return -1;
    }

    socketfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socketfd == -1)
    {
        spdlog::critical("Failed to create socket.");
        return -1;
    }

    // sockt = bind(socketfd, rp->ai_addr, rp->ai_addrlen);
    // if (sockt == 0)
    // {
    //     break;
    // }

    close(socketfd);

    return 0;
}