#include <iostream>

struct Server
{
    std::string host;
    std::string port;
};

void printHelloToOperatingSystem()
{
    std::cout << "Hello my friend Linux!" << std::endl;
    std::cout << "Hi MacOS!" << std::endl;
    std::cout << "OMG, Windows!" << std::endl;
}

Server* connectToHost()
{

    return new Server;
}

int main(int argc, char** argv)
{
    if (argc > 1) {
        std::string firstArg = argv[1];
        if (firstArg == "--version") {
            std::cout << "Hello!" << std::endl;
            std::cout << "My version is: " << APP_VERSION << std::endl;
            std::cout << "My configuration is: " << APP_BUILD_TYPE << std::endl;

            return 0;
        }
        else {
            std::cout << "Unknown parameter '" << firstArg << "'" << std::endl;
        }
    }
#if APP_IS_NICE
    printHelloToOperatingSystem();
#endif

#ifdef APP_ONLINE
    // ups, we have memory leak, let's run sanitizer
    const auto server = connectToHost();
//    std::cout << "Connecting to server " << server->host << "..." <<  std::endl;
#endif
    return 0;
}