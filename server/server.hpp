#include "utils/spdlog/spdlog.h"

class Server
{
private:
    int BindSocket(std::string const& port);
public:
    Server();
    ~Server();
    int startServer();
};


