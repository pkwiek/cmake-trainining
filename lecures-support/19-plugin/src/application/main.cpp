#include <iostream>
#include <string>
#include <filesystem>
#include <IPluginLoader.h>
#include <PluginLoaderFactory.h>

int main(int argc, char* argv[])
{
    std::string pluginsDir = argv[0];

    const auto applicationPath = std::filesystem::path(argv[0]);
    const auto applicationDirectory = applicationPath.parent_path();
    const auto pluginsDirectory = applicationDirectory / "plugins";

    auto pluginLoader = sevenide::plugin::loaderFactory::create();

    auto plugins = pluginLoader->LoadPlugins(pluginsDirectory);

    std::cout << "Hello World" << std::endl;
    std::cout << pluginsDir << std::endl;

    return 0;
}