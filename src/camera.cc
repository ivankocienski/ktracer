
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

void Camera::raytrace( Film& film, Scene &scene ) {

  float iw = 1.0 / film.width();
  float ih = 1.0 / film.height();

  // convert FOV to degrees per pixel (vertical)
  float angle = tan(M_PI * 0.5 * camera_fov / 180.0);

  for( int y = 0; y < film.height(); y++) {
    for( int x = 0; x < film.width(); x++ ) {
      
      // screen space ( xres X yres ) ->
      //   normal device coordinates ( 0 .. 1 )
      //     raster space ( -1 .. 1 )
      //       world space
      //         (TODO) translate/rotate
      float xx =     (2 * ((x + 0.5) * iw) - 1) * angle * film.ratio();
			float yy = (1 - 2 * ((y + 0.5) * ih)) * angle;

      Vector3 dir = Vector3( xx, yy, -1 );
      dir.normalize();

      RayHit hit = scene.trace( Ray( m_position, dir ));

      film.plot( x, y, floor(hit.luminance() * 255) );
    }

  }
}

