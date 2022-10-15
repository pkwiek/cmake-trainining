#include <filesystem>
#include <iostream>
#include <string>

#include <IPlugin.h>
#include <IPluginLoader.h>
#include <PluginLoaderFactory.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Provide plugin path to verify" << std::endl;
        return 1;
    }

    std::string pluginPath = argv[1];

    auto pluginLoader = sevenide::plugin::loaderFactory::create();

    std::cout << "Starting verification of plugin file: " << pluginPath << "..." << std::endl;
    std::cout << "Verification app can crash if getPluginInstance() function returns invalid type "
                 "or invalid value"
              << pluginPath << std::endl;
    sevenide::plugin::IPluginPtr plugin;

    try {
        plugin = pluginLoader->LoadPlugin(pluginPath);
    }

    catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
        return 2;
    }

    std::cout << "Plugin \"" << plugin->getPluginInfo().name << "\" verified successfully"
              << std::endl;

    return 0;
}