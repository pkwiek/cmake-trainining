#pragma once

#include <memory>
#include <string>

#include "PluginInfo.h"

namespace sevenide::plugin
{

class IObjectsFactory;
using IObjectsFactoryPtr = std::shared_ptr<IObjectsFactory>;

class IGraphicsFactory;
using IGraphicsFactoryPtr = std::shared_ptr<IGraphicsFactory>;

class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual PluginInfo getPluginInfo() = 0;
    virtual IObjectsFactoryPtr getObjectFactory() = 0;
    virtual IGraphicsFactoryPtr getGraphicsFactory() = 0;
};

using IPluginPtr = std::shared_ptr<IPlugin>;

} // namespace sevenide::plugin
