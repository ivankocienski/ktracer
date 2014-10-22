
#include "debug.h"

#include <math.h>
#include <float.h>

#include "matrix3.hh"
#include "operations.hh"
#include "camera.hh"
#include "ray.hh"

// in radians
const int camera_fov = 30;

Camera::Camera(int w, int h) {
  m_frame_width  = w;
  m_frame_height = h;
  m_frame_ratio = float(w) / float(h);

  m_film.resize( w * h );
}

void Camera::position( float x, float y, float z ) {
  m_position = Vector3( x, y, z );
}

void Camera::direction( float dx, float dy ) {
  m_heading = dx;
  m_pitch   = dy;
}

void Camera::raytrace( Window &window, Scene &scene ) {

  float iw = 1.0 / m_frame_width;
  float ih = 1.0 / m_frame_height;

  vector<unsigned char>::iterator film_it = m_film.begin();

  // convert FOV to degrees per pixel (vertical)
  float angle = tan(M_PI * 0.5 * camera_fov / 180.0);

  for( int y = 0; y < m_frame_height; y++) {
    for( int x = 0; x < m_frame_width; x++ ) {
      
      // screen space ( xres X yres ) ->
      //   normal device coordinates ( 0 .. 1 )
      //     raster space ( -1 .. 1 )
      //       world space
      //         (TODO) translate/rotate
      float xx =     (2 * ((x + 0.5) * iw) - 1) * angle * m_frame_ratio;
			float yy = (1 - 2 * ((y + 0.5) * ih)) * angle;

      Vector3 dir = Vector3( xx, yy, -1 );

      Matrix3 rot_mat = Matrix3::rotation_x_matrix( m_heading );

      vec3_mat3_multiply( dir, rot_mat );

      dir.normalize();

      RayHit hit = scene.trace( Ray( m_position, dir ));

      *film_it = floor(hit.luminance() * 255);

      film_it++;
    }
  }

  window.apply_film( m_film );
}

void Camera::outline( Window &window, Scene &scene ) {

  float iw = 1.0 / m_frame_width;
  float ih = 1.0 / m_frame_height;

  vector<unsigned char>::iterator film_it = m_film.begin();

  // convert FOV to degrees per pixel (vertical)
  float angle = tan(M_PI * 0.5 * camera_fov / 180.0);

  for( int y = 0; y < m_frame_height; y++) {
    for( int x = 0; x < m_frame_width; x++ ) {
      
      // screen space ( xres X yres ) ->
      //   normal device coordinates ( 0 .. 1 )
      //     raster space ( -1 .. 1 )
      //       world space
      //         (TODO) translate/rotate
      float xx =     (2 * ((x + 0.5) * iw) - 1) * angle * m_frame_ratio;
			float yy = (1 - 2 * ((y + 0.5) * ih)) * angle;

      Vector3 dir = Vector3( xx, yy, -1 );

      Matrix3 rot_mat = Matrix3::rotation_x_matrix( m_heading );

      vec3_mat3_multiply( dir, rot_mat );

      dir.normalize();

      RayHit hit = scene.outline( Ray( m_position, dir ));

      *film_it = floor(hit.luminance() * 255);

      film_it++;
    }
  }

  window.apply_film( m_film );
}

void Camera::move( float d ) { 
  m_position.x += -sin( m_heading ) * d;
  m_position.z += -cos( m_heading ) * d; 
}

void Camera::turn( float d ) {
  m_heading += d; 
}
