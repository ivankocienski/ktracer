
#include <math.h>

#include "sphere.hh"

Sphere::Sphere( Vector3 const &p, float r ) {
  m_position = p;
  m_radius = r;
}

bool Sphere::has_hit( const Vector3 &ray_pos, const Vector3 &ray_dir, float *dist ) {
  
  // we only have one sphere...

  Vector3 l = m_position - ray_pos;
  float tca = l.dot( ray_dir );

  // behind us?
  if( tca < 0 ) return false;

  float d = sqrt( l.dot(l) - tca * tca );

  if( d < 0 ) return false;
  if( d > m_radius ) return false;

  // where on the sphere did we hit>
  float hit_offset = sqrt( m_radius * m_radius - d * d );

  float h1 = tca - hit_offset;
  float h2 = tca + hit_offset;

  if( dist ) *dist = h1 < h2 ? h1 : h2;

  return true;
}

