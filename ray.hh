
#pragma once

#include "vector3.hh"
#include "sphere.hh"

class Ray {
private:

  Vector3 m_position;
  Vector3 m_direction;
  Sphere *m_sphere;
  unsigned char m_color;

public:

  Ray( Vector3&, Vector3&, Sphere& );
  void trace();
  unsigned char color();
};

