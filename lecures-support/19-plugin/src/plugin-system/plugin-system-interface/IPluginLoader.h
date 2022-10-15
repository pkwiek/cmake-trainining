#pragma once

#include <string>

#include <SharedPtr.h>
#include <vector>

namespace sevenide::plugin
{

class IPlugin;
using IPluginPtr = memory::SharedPtr<IPlugin>;

class IPluginLoader
{
public:
    virtual ~IPluginLoader() = default;

    virtual IPluginPtr LoadPlugin(const std::string& path) = 0;
    virtual std::vector<IPluginPtr> LoadPlugins(const std::string& directory) noexcept = 0;
};

} // namespace
