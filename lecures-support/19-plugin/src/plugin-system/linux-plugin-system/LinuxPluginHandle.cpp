#include "LinuxPluginHandle.h"

#include <filesystem>
#include <stdexcept>

#include <IPlugin.h>
#include <dlfcn.h>

namespace sevenide::plugin
{

LinuxPluginHandle::~LinuxPluginHandle()
{
    releaseHandle();
}

LinuxPluginHandle::LinuxPluginHandle(LinuxPluginHandle&& moveFrom)
  : pluginHandle(moveFrom.pluginHandle)
{
    moveFrom.pluginHandle = nullptr;
}

LinuxPluginHandle& LinuxPluginHandle::operator=(LinuxPluginHandle&& moveFrom)
{
    if (&moveFrom == this) {
        return *this;
    }
    releaseHandle();
    pluginHandle = moveFrom.pluginHandle;
    moveFrom.pluginHandle = nullptr;
    return *this;
}

LinuxPluginHandle::LinuxPluginHandle(const std::string& path)
{
    const auto pluginPath = std::filesystem::path(path);

    pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY | RTLD_GLOBAL);

    if (nullptr == pluginHandle) {
        std::stringstream stream;
        stream << "Cannot open library " << path;
        throw std::runtime_error(stream.str());
    }

    typedef IPluginPtr (*func_type)();

    void* voidHandle = dlsym(pluginHandle, "getPluginInstance");

    auto getPluginInstanceFunction = reinterpret_cast<func_type>(voidHandle);

    if (nullptr == getPluginInstanceFunction) {
        std::stringstream stream;
        stream << "Cannot find function \"getPluginInstance()\" in " << path << " library. ";
        stream << "Did you remember about preventing mangling for it? (extern \"C\")?";
        throw std::runtime_error(stream.str());
    }

    plugin = getPluginInstanceFunction();

    if (!plugin) {
        std::stringstream stream;
        stream << "getPluginInstance() from library " << path << " returns empty object";
        throw std::runtime_error(stream.str());
    }

    const auto pluginInfo = plugin->getPluginInfo();

    if (pluginInfo.name.empty()) {
        std::stringstream stream;
        stream << "Plugin " << path << " has no name";
        throw std::runtime_error(stream.str());
    }

    if (pluginInfo.vendor.empty()) {
        std::stringstream stream;
        stream << "Plugin " << path << " has no vendor";
        throw std::runtime_error(stream.str());
    }
}

IPluginPtr LinuxPluginHandle::getPlugin() const noexcept
{
    return plugin;
}

void LinuxPluginHandle::releaseHandle()
{
    if (nullptr == pluginHandle) {
        return;
    }
    dlclose(pluginHandle);
}

} // namespace sevenide::plugin
