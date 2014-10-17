
#include "ray.hh"

RayHit::RayHit( float d, float i ) {
  m_distance  = d;
  m_luminance = i;
}

float RayHit::luminance() {
  return m_luminance;
}

Ray::Ray( const Vector3 &p, const Vector3 &d ) {
  m_position  = p;
  m_direction = d;
}

