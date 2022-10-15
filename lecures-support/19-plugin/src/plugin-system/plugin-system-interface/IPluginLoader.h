#pragma once

#include <memory>
#include <string>
#include <vector>

namespace sevenide::plugin
{

class IPlugin;
using IPluginPtr = std::shared_ptr<IPlugin>;

class IPluginLoader
{
public:
    virtual ~IPluginLoader() = default;

    virtual IPluginPtr LoadPlugin(const std::string& path) = 0;
    virtual std::vector<IPluginPtr> LoadPlugins(const std::string& directory) noexcept = 0;
};

} // namespace sevenide::plugin
