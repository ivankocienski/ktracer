
#include "debug.h"

#include <math.h>
#include <float.h>

#include "camera.hh"
#include "ray.hh"

// in radians
const int camera_fov = 30;

Camera::Camera() {
}

void Camera::position( float x, float y, float z ) {
  m_position = Vector3( x, y, z );
}

void Camera::direction( float dx, float dy ) {
  m_heading = dx;
  m_pitch   = dy;
}

float Camera::z_at( int x, int y ) {
  if( x < 0 || x >= m_zbw ) return 0;
  if( y < 0 || y >= m_zbh ) return 0;

  return m_zbuff[ y * m_zbw + x ]; 
}

void Camera::raytrace( Film& film, std::vector<Sphere> &spheres, Plane &plane, Vector3 &light_dir ) {

  float iw = 1.0 / film.width();
  float ih = 1.0 / film.height();

  m_zbw = film.width();
  m_zbh = film.height();
  m_zbuff.resize( film.width() * film.height() );

  // TODO: figure out how/why this works.
  float angle = tan(M_PI * 0.5 * camera_fov / 180.0); //tan((M_PI * 2) / (float)camera_fov);

  for( int y = 0; y < film.height(); y++) {

    for( int x = 0; x < film.width(); x++ ) {
      
      float d;
      float xx =     (2 * ((x + 0.5) * iw) - 1) * angle * film.ratio();
			float yy = (1 - 2 * ((y + 0.5) * ih)) * angle;

      Vector3 dir = Vector3( xx, yy, -1 );
      dir.normalize();

      Ray ray( m_position, dir, spheres, plane, light_dir );

      ray.trace(&d);
      film.plot( x, y, ray.color() );

      m_zbuff[ y * m_zbw + x ] = d;
      
    }

  }
}

