#pragma once

#include <IPlugin.h>

extern "C" SEVENIDE_OPENGL_GRAPHICS_API sevenide::plugin::IPluginPtr getPluginInstance();

namespace sevenide::plugin
{

class OpenGLGraphicsPlugin : public IPlugin
{
public:
    PluginInfo getPluginInfo() override;
    IObjectsFactoryPtr getObjectFactory() override;
    IGraphicsFactoryPtr getGraphicsFactory() override;
};

} // namespace sevenide::plugin
