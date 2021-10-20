#include "../includes/spdlog/spdlog.h"

class server
{
private:
    int bind_socket(std::string const& port);
public:
    server();
    ~server();
    int start_server();
};


