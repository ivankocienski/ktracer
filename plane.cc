
#include <math.h>

#include "plane.hh"

Plane::Plane( const Vector3 &p, const Vector3 &d ) {
  m_position = p;
  m_direction = d;
}

bool Plane::has_hit( Vector3& ray_pos, Vector3& ray_dir, float* dist ) {

  float n = ray_dir.dot( m_direction );

  if( n <= 0 ) return false;

  float t = (ray_pos - m_position).dot( m_direction ); 

  if( dist ) *dist = t / n;
  
  return true;
}
