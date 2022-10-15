#pragma once

#include <memory>

namespace sevenide::plugin
{
class IPluginLoader;

namespace loaderFactory
{

std::unique_ptr<IPluginLoader> create() noexcept;

} // namespace loaderFactory
} // namespace sevenide::plugin
