#pragma once

#include <string>

#include "ClassId.h"

namespace sevenide::metaclass
{

struct ClassInfo
{
    std::string name;
    ClassId classId;
};

} // namespace sevenide::metaclass