
#pragma once

#include "vector3.hh"
#include "film.hh"

class Camera {
private:

  Vector3 m_position;
  Vector3 m_direction;

public:

  Camera();

  void position( float, float, float );
  void direction( float, float, float );
  void raytrace( Film& );
};

