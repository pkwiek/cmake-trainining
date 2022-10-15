#pragma once

#include "IServerAddressProvider.h"

class SimpleServerAddressProvider : public IServerAddressProvider
{
public:
    std::string getHostAddress() override;
};
