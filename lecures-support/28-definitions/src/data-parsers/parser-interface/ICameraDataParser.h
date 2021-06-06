#pragma once

#include <string>

#include "CameraData.h"

namespace parsers
{
class ICameraDataParser
{
public:
    virtual ~ICameraDataParser() = default;

    virtual data::CameraData parseContent(const std::string& content) = 0;
    virtual std::string dataToString(const data::CameraData& data) = 0;
};
} // namespace parsers