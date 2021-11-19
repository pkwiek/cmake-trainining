#pragma once

#include <string>

#include "CameraData.h"

namespace parsers
{
class ICameraDataParser
{
public:
    virtual ~ICameraDataParser() = default;

    /// \brief Converts text to structure data::CameraData
    virtual data::CameraData parseContent(const std::string& content) = 0;

    /// \brief Converts structure data::CameraData to text
    virtual std::string dataToString(const data::CameraData& data) = 0;
};
} // namespace parsers