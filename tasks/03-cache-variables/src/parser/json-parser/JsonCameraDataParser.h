#pragma once

#include "ICameraDataParser.h"

namespace parsers
{

class JsonCameraDataParser : public ICameraDataParser
{
public:
    ~JsonCameraDataParser() override = default;
    JsonCameraDataParser() = default;

    data::CameraData parseContent(const std::string& content) override;
    std::string dataToString(const data::CameraData& data) override;
};

} // namespace parsers
