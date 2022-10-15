#pragma once

#include <SharedPtr.h>

namespace sevenide::graphics2d
{
class ICanvas;
using ICanvasPtr = memory::SharedPtr<ICanvas>;
}

namespace sevenide::plugin
{

class IGraphicsFactory
{
public:
    virtual graphics2d::ICanvasPtr getCanvas() = 0;

};

} // namespace sevenide::plugin