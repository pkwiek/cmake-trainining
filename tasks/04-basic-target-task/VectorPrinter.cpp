#include "VectorPrinter.h"

#include "Vector3.h"

std::ostream &operator<<(std::ostream &stream, const Vector3 &vec) {
  return stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}
