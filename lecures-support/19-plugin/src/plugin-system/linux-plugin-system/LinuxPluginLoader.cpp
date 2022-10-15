#include "LinuxPluginLoader.h"

#include <algorithm>
#include <filesystem>
#include <functional>
#include <iostream>

#include <IPlugin.h>
#include <dlfcn.h>

#include "LinuxPluginHandle.h"

namespace sevenide::plugin
{
namespace
{

using getPluginInstanceFunction = IPlugin* (*)();
typedef IPlugin* (*func_type)();

bool hasFilePluginExtension(const std::filesystem::path& file)
{
    return file.extension() == ".so";
}

} // namespace

std::vector<IPluginPtr> LinuxPluginLoader::LoadPlugins(const std::string& directory) noexcept
{
    const auto directoryPath = std::filesystem::path(directory);
    if (!std::filesystem::exists(directoryPath)) {
        std::cerr << "Directory " << directory << " does not exists" << std::endl;
        return {};
    }

    std::vector<IPluginPtr> loadedPlugins;

    for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
        std::cout << "Considering " << file << std::endl;
        if (!file.is_regular_file()) {
            std::cout << file << " is not regular file" << std::endl;
            continue;
        }
        if (!hasFilePluginExtension(file)) {
            continue;
        }

        try {
            auto plugin = LoadPlugin(std::string(file.path()));
            loadedPlugins.emplace_back(std::move(plugin));
        }
        catch (const std::runtime_error& error) {
            std::cerr << error.what() << std::endl;
        }
    }

    return loadedPlugins;
}

IPluginPtr LinuxPluginLoader::LoadPlugin(const std::string& path)
{
    const auto it = std::find_if(plugins.cbegin(),
                                 plugins.cend(),
                                 [path](const PluginRecord& pluginRecord) {
                                     return pluginRecord.filePath == path;
                                 });
    if (it != plugins.end()) {
        return it->pluginHandle.getPlugin();
    }

    auto pluginHandle = LinuxPluginHandle(path);
    auto plugin = pluginHandle.getPlugin();
    plugins.push_back({path, std::move(pluginHandle)});

    const auto pluginInfo = plugin->getPluginInfo();

    std::cout << "Loaded plugin " << pluginInfo.name << "\n";
    std::cout << "Plugin Version " << pluginInfo.pluginVersion.toString() << "\n";
    std::cout << "For for SevenIDE Version " << pluginInfo.engineVersion.toString() << "\n";
    std::cout << "Provider: " << pluginInfo.vendor << std::endl;

    return plugin;
}

} // namespace sevenide::plugin
