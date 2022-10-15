#include "Objects2DPlugin.h"

sevenide::memory::SharedPtr<sevenide::plugin::IPlugin> getPluginInstance()
{
    return std::make_shared<sevenide::objects2d::Objects2DPlugin>();
}

namespace sevenide::objects2d
{

plugin::PluginInfo Objects2DPlugin::getPluginInfo()
{
    const plugin::PluginInfo info{"Objects 2D plugin",
                                  "Quick Turn Studio GmbH",
                                  Version("0.1"),
                                  Version("1.0.0")};
    return info;
}

plugin::IObjectsFactoryPtr Objects2DPlugin::getObjectFactory()
{
    return nullptr;
}

plugin::IGraphicsFactoryPtr Objects2DPlugin::getGraphicsFactory()
{
    return nullptr;
}

} // namespace sevenide::objects2d
