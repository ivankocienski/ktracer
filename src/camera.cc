
#include "debug.h"

#include <math.h>
#include <float.h>

#include "matrix3.hh"
#include "operations.hh"
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

      Matrix3 rot_mat = Matrix3::rotation_x_matrix( m_heading );

      vec3_mat3_multiply( dir, rot_mat );

      dir.normalize();

      RayHit hit = scene.trace( Ray( m_position, dir ));

      film.plot( x, y, floor(hit.luminance() * 255) );
    }

  }
}

void Camera::move( float d ) { 
  m_position.x += cos( m_heading ) * d;
  m_position.z += sin( m_heading ) * d; 
}

void Camera::turn( float d ) {
  m_heading += d; 
}
