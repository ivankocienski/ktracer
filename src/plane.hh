
#pragma once

#include <vector>

#include "scene-object.hh"
#include "vector3.hh"

class Plane : public SceneObject {
private:

  Vector3 m_direction;

public:

  Plane( const Vector3&, const Material&, const Vector3& );

  bool has_hit( const Vector3&, const Vector3&, float* ) const;
  float luminance( const Vector3&, const Vector3& ) const;
  Vector3 normal( const Vector3& ) const;
};
