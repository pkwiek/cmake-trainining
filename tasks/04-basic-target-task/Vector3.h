#pragma once

struct Vector3 {
  float x = 0.0F;
  float y = 0.0F;
  float z = 0.0F;

  Vector3 operator+(const Vector3 &vec);
  Vector3 operator-(const Vector3 &vec);
};
