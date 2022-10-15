#include "OpenGLGraphicsPlugin.h"

#include <memory>

sevenide::plugin::IPluginPtr getPluginInstance()
{
    return std::make_shared<sevenide::plugin::OpenGLGraphicsPlugin>();
}

namespace sevenide::plugin
{

PluginInfo OpenGLGraphicsPlugin::getPluginInfo()
{
    return {"SevenIDE OpenGL Graphics Plugin", "Quick Turn Studio GmbH", Version(""), Version("")};
}

IObjectsFactoryPtr OpenGLGraphicsPlugin::getObjectFactory()
{
    return nullptr;
}

IGraphicsFactoryPtr OpenGLGraphicsPlugin::getGraphicsFactory()
{
    return nullptr;
}

} // namespace sevenide::plugin