#include <iostream>

void printHelloToOperatingSystem()
{
    std::cout << "Hello my friend Linux!" << std::endl;
    std::cout << "Hi MacOS!" << std::endl;
    std::cout << "OMG, Windows!" << std::endl;
}

void connectToHost()
{
    std::cout << "Connecting to server..." << std::endl;
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
    connectToHost();
#endif
    return 0;
}