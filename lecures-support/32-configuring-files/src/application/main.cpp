#include <iostream>

#include <FileLoader.h>
#include <JsonCameraDataParser.h>

std::unique_ptr<parsers::ICameraDataParser> createParserFactory()
{
    return std::make_unique<parsers::JsonCameraDataParser>();
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Please provide path to file" << std::endl;
        return 1;
    }

    std::string firstArg = argv[1];

    const auto fileContent = file::loadTextFile(firstArg);



    return 0;
}