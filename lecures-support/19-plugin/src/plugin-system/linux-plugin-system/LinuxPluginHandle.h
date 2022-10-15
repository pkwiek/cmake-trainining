#pragma once

#include <memory>
#include <string>

#include "LinuxPluginHandle.h"

namespace sevenide::plugin
{

class IPlugin;
using IPluginPtr = std::shared_ptr<IPlugin>;

class LinuxPluginHandle //: public IPluginHandle
{
public:
    ~LinuxPluginHandle();
    explicit LinuxPluginHandle(const std::string& path);

    LinuxPluginHandle(const LinuxPluginHandle&) = delete;
    LinuxPluginHandle& operator = (const LinuxPluginHandle&) = delete;

    LinuxPluginHandle(LinuxPluginHandle&& moveFrom);
    LinuxPluginHandle& operator = (LinuxPluginHandle&& moveFrom);

    IPluginPtr getPlugin() const noexcept;

private:
    void releaseHandle();

private:
    void* pluginHandle = nullptr;
    IPluginPtr plugin;
};

} // namespace sevenide::plugin
