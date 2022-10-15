#pragma once

#include <string>

#include <SharedPtr.h>

#include "PluginInfo.h"

namespace sevenide::plugin
{

class IObjectsFactory;
using IObjectsFactoryPtr = memory::SharedPtr<IObjectsFactory>;

class IGraphicsFactory;
using IGraphicsFactoryPtr = memory::SharedPtr<IGraphicsFactory>;

class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual PluginInfo getPluginInfo() = 0;
    virtual IObjectsFactoryPtr getObjectFactory() = 0;
    virtual IGraphicsFactoryPtr getGraphicsFactory() = 0;
};

using IPluginPtr = memory::SharedPtr<IPlugin>;

} // namespace sevenide::plugin
