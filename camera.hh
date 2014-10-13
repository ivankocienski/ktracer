
#pragma once

#include "vector3.hh"
#include "film.hh"
#include "sphere.hh"

class Camera {
private:

  Vector3 m_position;

  /* TODO: use quaternions */
  float m_heading;
  float m_pitch;

public:

  Camera();

  void position( float, float, float );
  void direction( float, float );
  void raytrace( Film&, Sphere& );
};

