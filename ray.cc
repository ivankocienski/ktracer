
#include <float.h>

#include "ray.hh"

Ray::Ray( Vector3 &p, Vector3 &d, Sphere &sphere, Plane &plane ) {
  m_position  = p;
  m_direction = d;
  m_sphere    = &sphere;
  m_plane     = &plane;
}

void Ray::trace() {

  float dist = FLT_MAX;
  float d;

  m_color = 0;

  if( m_sphere->has_hit( m_position, m_direction, &d ) ) {
    dist = d;
    m_color = 255;
  }

  if( m_plane->has_hit( m_position, m_direction, &d ) ) {
    if( d < dist ) {
      dist = d;
      m_color = 100;
    }
  }

}

unsigned char Ray::color() {
  return m_color;
}

