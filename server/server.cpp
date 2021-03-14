#include "spdlog/spdlog.h"
#include "server.hpp"

Server::Server()
{
}

Server::~Server()
{
}

int Server::startServer()
{
    spdlog::info("Welcome to cherokee!");
    spdlog::error("Some error message with arg: {}", 1);

    return 0;
}