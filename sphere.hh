
#pragma once

#include "scene-object.hh"
#include "vector3.hh"

class Sphere : public SceneObject {
private:

  Vector3 m_position;
  float   m_radius;

public:

  Sphere( Vector3 const&, float );

  bool has_hit( const Vector3&, const Vector3&, float* );

  float luminance( Vector3&, Vector3& );

};

