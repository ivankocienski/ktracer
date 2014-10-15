
#include <float.h>

#include "ray.hh"

Ray::Ray( Vector3 &p, Vector3 &d, std::vector<Sphere> &sph, Plane &plane ) : m_spheres( sph ) {
  m_position  = p;
  m_direction = d;
  m_plane     = &plane;
}

void Ray::trace(float *rd) {

  float dist = FLT_MAX;
  float d;
  unsigned char color = 0;

  m_color = 0;

  for( std::vector<Sphere>::iterator it = m_spheres.begin(); it != m_spheres.end(); it++ ) {
    if( (*it).has_hit( m_position, m_direction, &d ) ) {
      if( d < dist ) {
        dist = d;
        color = 255;
      }
    }
  }

  if( m_plane->has_hit( m_position, m_direction, &d ) ) {
    if( d < dist ) {
      dist = d;
      color = 100;
    }
  }
  

  if( dist >= 1 && dist <= 25 ) {
    m_color = (float)color * (1.0 - (dist / 25.0));

  }

  if( dist < FLT_MAX )
    *rd = d;
  else
    *rd = -1;
}

unsigned char Ray::color() {
  return m_color;
}

