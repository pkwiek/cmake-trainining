#pragma once

#include <string>

class IServerAddressProvider
{
public:
    virtual ~IServerAddressProvider() = default;
    virtual std::string getHostAddress() = 0;
};
