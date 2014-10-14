
#pragma once

#include "vector3.hh"

class Plane {
public:

  Vector3 m_position;
  Vector3 m_direction;

  Plane( const Vector3&, const Vector3& );

  bool has_hit( Vector3&, Vector3&, float* );
};
