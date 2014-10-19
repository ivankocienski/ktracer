
#pragma once

#include "vector3.hh"
#include "material.hh"

class RayHit {
public:

  float m_distance;
  float m_luminance;
  const Material *m_material;

  RayHit( float, float, const Material* );

  float luminance();
};

class Ray {
public:

  Vector3 m_position;
  Vector3 m_direction;

  Ray( const Vector3&, const Vector3& ); 

  Ray reflect( float, const Vector3& ) const;
};

