
#include <math.h>

#include "ray.hh"

Ray::Ray( Vector3 &p, Vector3 &d, Sphere &sphere ) {
  m_position  = p;
  m_direction = d;
  m_sphere    = &sphere;
}

void Ray::trace() {

  m_color = 0;

  // we only have one sphere...

  Vector3 l = m_sphere->m_position - m_position;
  float tca = l.dot( m_direction );

  // behind us?
  if( tca < 0 ) return;

  float d = sqrt( l.dot(l) - tca * tca );

  if( d < 0 ) return;
  if( d > m_sphere->m_radius ) return;

  // where on the sphere did we hit>
  float hit_offset = sqrt( m_sphere->m_radius * m_sphere->m_radius - d * d );

  float h1 = tca - hit_offset;
  float h2 = tca + hit_offset;

  m_color = 255;
}

unsigned char Ray::color() {
  return m_color;
}

