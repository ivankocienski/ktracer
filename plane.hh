
#pragma once

#include <vector>

#include "scene-object.hh"
#include "vector3.hh"

class Plane : public SceneObject {
private:

  Vector3 m_position;
  Vector3 m_direction;

public:

  Plane( const Vector3&, const Vector3& );

  bool has_hit( const Vector3&, const Vector3&, float* );
  float luminance( const Vector3&, const Vector3& );
};
