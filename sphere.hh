
#pragma once

#include "vector3.hh"

class Sphere {
public:
  
  Vector3 m_position;
  float   m_radius;

  Sphere( Vector3 const&, float );

  bool has_hit( const Vector3&, const Vector3&, float* );

};

