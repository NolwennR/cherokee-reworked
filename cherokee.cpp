#include <iostream>
#include "server/server.hpp"

int main()
{
    Server server = Server();
    
    server.startServer();

    return 0;
}
