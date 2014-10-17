
#pragma once

#include <vector>

#include "vector3.hh"
#include "film.hh"
#include "scene.hh"

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
  void raytrace( Film&, Scene& );
};

