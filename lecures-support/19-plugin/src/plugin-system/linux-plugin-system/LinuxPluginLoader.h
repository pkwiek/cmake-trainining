#pragma once

#include <unordered_map>

#include <IPluginLoader.h>

#include "LinuxPluginHandle.h"
#include "PluginInfo.h"

namespace sevenide::plugin
{

class LinuxPluginLoader : public IPluginLoader
{
public:
    LinuxPluginLoader() = default;

    IPluginPtr LoadPlugin(const std::string& path) override;
    std::vector<IPluginPtr> LoadPlugins(const std::string& directory) noexcept override;

private:
    struct PluginRecord
    {
        std::string filePath;
        LinuxPluginHandle pluginHandle;
    };

    std::vector<PluginRecord> plugins;
};

} // namespace sevenide::plugin
