#include <iostream>
#include "server/server.hpp"

int main()
{
    server* srv = new server();
    
    srv->start_server();

    return 0;
}
