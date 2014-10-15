
#include <math.h>


#include "debug.h"

#include "plane.hh"

using namespace std;

Plane::Plane( const Vector3 &p, const Vector3 &d ) {
  m_position = p;
  m_direction = d;

  m_tex_w = 8 ;
  m_tex_h = 8;
}

bool Plane::has_hit( Vector3& ray_pos, Vector3& ray_dir, float* dist ) {

  float n = ray_dir.dot( m_direction );

  if( n >= 0 ) return false;

  float t = (m_position - ray_pos ).dot( m_direction ); 

  if( dist ) *dist = t / n;
  
  return true;
}

float Plane::luminance( Vector3& hit_pos ) {
  
  Vector3 offset = m_position - hit_pos;

  float u = offset.x - floor(offset.x);
  float v = offset.z - floor(offset.z);

  if(u < 0 ) u = 1 - u;
  if(v < 0 ) v = 1 - v;

  u *= 128;
  v *= 128;

  return ((int)u ^ (int)v);
}
