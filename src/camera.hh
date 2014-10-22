
#pragma once

#include <vector>

#include "vector3.hh"
#include "scene.hh"
#include "window.hh"

class Camera {
private:

  int m_frame_width;
  int m_frame_height;
  float m_frame_ratio;

  std::vector<unsigned char> m_film;
  
  Vector3 m_position;

  /* TODO: use quaternions */
  float m_heading;
  float m_pitch;

public:

  Camera(int, int);

  void position( float, float, float );
  void direction( float, float );
  void raytrace( Window&, Scene& );
  void outline( Window&, Scene& );

  // these should be in some kind of 'player' class

  void move( float );
  void turn( float );
};

