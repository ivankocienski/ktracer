
#pragma once

#include <vector>

#include "vector3.hh"
#include "sphere.hh"
#include "plane.hh"

class Ray {
private:

  Vector3 m_position;
  Vector3 m_direction;
  Plane  *m_plane;
  unsigned char m_color;

  std::vector<Sphere> &m_spheres;

  Vector3 &m_light_dir;

public:

  Ray( Vector3&, Vector3&, std::vector<Sphere>&, Plane&, Vector3& );
  void trace(float *);
  unsigned char color();
};

