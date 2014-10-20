
#include <math.h>

#include "debug.h"

#include "plane.hh"

using namespace std;

Plane::Plane( const Vector3 &p, const Material &mat, const Vector3 &d ) : SceneObject(p, mat) {
  m_direction = d;
}

bool Plane::has_hit( const Vector3& ray_pos, const Vector3& ray_dir, float* dist ) const {

  float n = ray_dir.dot( m_direction );

  if( n >= 0 ) return false;

  float t = (m_position - ray_pos ).dot( m_direction ); 

  if( dist ) *dist = t / n;

  
  return true;
}

float Plane::luminance( const Vector3& hit_pos, const Vector3& l ) const {
  
  Vector3 offset = m_position - hit_pos;

  float u = offset.x - floor(offset.x);
  float v = offset.z - floor(offset.z);

  if(u < 0 ) u = 1 - u;
  if(v < 0 ) v = 1 - v;

  u *= 128;
  v *= 128;

  unsigned char p = (int)u ^ (int)v;

  return p / 255.0;
}

Vector3 Plane::normal( const Vector3& ) const {
  return m_direction;
}
