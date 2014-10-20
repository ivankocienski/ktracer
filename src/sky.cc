
#include <float.h>

#include "sky.hh"

Sky::Sky() : SceneObject( Vector3(), Material() ) { 
  m_material.m_falloff = false;
}

bool Sky::has_hit( const Vector3& hit, const Vector3& light, float* d ) const {

  if(d) *d = FLT_MAX;

  return true;
}

float Sky::luminance( const Vector3&, const Vector3& ) const {
  return 0.5;
}

Vector3 Sky::normal( const Vector3& i ) const {
  Vector3 v = i;

  v.normalize();

  return v;
}

