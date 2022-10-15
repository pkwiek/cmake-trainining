#pragma once

#include <ostream>

struct Vector3;

std::ostream& operator << (std::ostream& stream, const Vector3& vec);
