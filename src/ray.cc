
#include "ray.hh"

RayHit::RayHit( float d, float i, const Material* m ) {
  m_distance  = d;
  m_luminance = i;
  m_material  = m;
}

float RayHit::luminance() {
  return m_luminance;
}

Ray::Ray( const Vector3 &p, const Vector3 &d ) {
  m_position  = p;
  m_direction = d;
}

Ray Ray::reflect( float dist, const Vector3& normal ) const {

  Vector3 new_pos = m_position + m_direction * dist;

  Vector3 new_dir = m_direction - normal * (2 * normal.dot(m_direction));

  return Ray( new_pos, new_dir );
}

