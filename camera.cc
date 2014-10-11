
#include "camera.hh"

Camera::Camera() {
}

void Camera::position( float x, float y, float z ) {
  m_position = Vector3( x, y, z );
}

void Camera::direction( float dx, float dy, float dz ) {
  m_direction = Vector3( dx, dy, dz ); 
}

void Camera::raytrace( Film& film ) {

  for( int y = 0; y < film.height(); y++)
    for( int x = 0; x < film.width(); x++ )
      film.plot( x, y, x ^ y );
}

