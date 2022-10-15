#pragma once

#include <IPlugin.h>
#include <SharedPtr.h>

//extern "C" SEVENIDE_OBJECT2D_API sevenide::memory::SharedPtr<sevenide::plugin::IPlugin>
SEVENIDE_OBJECT2D_API sevenide::memory::SharedPtr<sevenide::plugin::IPlugin>
getPluginInstance();

namespace sevenide::objects2d
{

class Objects2DPlugin : public plugin::IPlugin
{
public:
    plugin::PluginInfo getPluginInfo() override;
    plugin::IObjectsFactoryPtr getObjectFactory() override;
    plugin::IGraphicsFactoryPtr getGraphicsFactory() override;
};

} // namespace sevenide::objects2d
