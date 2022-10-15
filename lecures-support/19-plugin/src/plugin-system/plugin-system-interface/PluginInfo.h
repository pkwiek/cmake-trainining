#pragma once

#include <string>

#include "Version.h"

namespace sevenide::plugin
{

struct PluginInfo
{
    std::string name;
    std::string vendor;
    Version pluginVersion;
    Version engineVersion;
};

} // namespace sevenide::plugin