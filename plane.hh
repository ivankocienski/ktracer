
#pragma once

#include <vector>

#include "vector3.hh"

class Plane {
public:

  Vector3 m_position;
  Vector3 m_direction;

  std::vector<unsigned char> m_texture;
  int m_tex_w;
  int m_tex_h;

  Plane( const Vector3&, const Vector3& );

  bool has_hit( Vector3&, Vector3&, float* );
  float luminance( Vector3& );
};
