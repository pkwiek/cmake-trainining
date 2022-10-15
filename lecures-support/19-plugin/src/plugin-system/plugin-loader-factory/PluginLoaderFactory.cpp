#include "PluginLoaderFactory.h"

#ifdef SEVENIDE_LINUX

#include <LinuxPluginLoader.h>

#endif

namespace sevenide::plugin::loaderFactory
{

std::unique_ptr<IPluginLoader> create() noexcept
{
#ifdef SEVENIDE_LINUX
    return std::make_unique<LinuxPluginLoader>();
#else
    #error "Unsupprted platform"
#endif
}

}