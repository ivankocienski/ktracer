
#pragma once

#include "vector3.hh"
#include "sphere.hh"
#include "plane.hh"

class Ray {
private:

  Vector3 m_position;
  Vector3 m_direction;
  Sphere *m_sphere;
  Plane  *m_plane;
  unsigned char m_color;

public:

  Ray( Vector3&, Vector3&, Sphere&, Plane& );
  void trace();
  unsigned char color();
};

