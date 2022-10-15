#pragma once

#include <string>
#include <istream>

namespace sevenide
{

class Version
{
public:
    explicit Version(const std::string& version);

    int getMajorVersion() const;
    int getMinorVersion() const;
    int getPatchVersion() const;
    int getTweakVersion() const;

    std::string toString() const;

private:
    int major = 0;
    int minor = 0;
    int patch = 0;
    int tweak = 0;
};

}