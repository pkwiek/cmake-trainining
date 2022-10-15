#pragma once

#include <memory>

#include <IPlugin.h>

extern "C" SEVENIDE_OBJECT2D_API std::shared_ptr<sevenide::plugin::IPlugin> getPluginInstance();
// SEVENIDE_OBJECT2D_API std::shared_ptr<sevenide::plugin::IPlugin> getPluginInstance();

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
