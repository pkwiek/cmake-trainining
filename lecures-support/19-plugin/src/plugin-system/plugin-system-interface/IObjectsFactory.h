#pragma once

#include <vector>

#include <SharedPtr.h>

#include "ClassInfo.h"

namespace sevenide::metaclass
{

class IObject;

class IObjectsFactory
{
public:
    virtual ~IObjectsFactory() = default;

    std::vector<ClassInfo> getSupportedObjects();

    memory::SharedPtr<IObject> create(ClassId classId);

};

} // namespace sevenide::metaclass