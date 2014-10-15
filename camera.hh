
#pragma once

#include <vector>

#include "vector3.hh"
#include "film.hh"
#include "sphere.hh"
#include "plane.hh"

class Camera {
private:

  Vector3 m_position;

  std::vector<float> m_zbuff;
  int m_zbw; // z buffer width
  int m_zbh;
  
  /* TODO: use quaternions */
  float m_heading;
  float m_pitch;

public:

  Camera();

  void position( float, float, float );
  void direction( float, float );
  void raytrace( Film&, std::vector<Sphere>&, Plane&, Vector3& );

  float z_at( int, int );
};

