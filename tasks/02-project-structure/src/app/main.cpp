#include <iostream>
#include <memory>

#include "FileLoader.h"
#include "JsonCameraDataParser.h"
#include "SimpleServerAddressProvider.h"

std::unique_ptr<parsers::ICameraDataParser> createParserFactory()
{
    return std::make_unique<parsers::JsonCameraDataParser>();
}

std::unique_ptr<IServerAddressProvider> createAddressProvider()
{
    return std::make_unique<SimpleServerAddressProvider>();
}


int main(int argc, char** argv)
{
    const auto provider = createAddressProvider();
    std::cout << "Connecting to " << provider->getHostAddress() << " ..." << std::endl;

    if (argc < 2) {
        std::cout << "Please provide path to file" << std::endl;
        return 1;
    }

    std::string firstArg = argv[1];

    const auto fileContent = file::loadTextFile(firstArg);

    return 0;
}