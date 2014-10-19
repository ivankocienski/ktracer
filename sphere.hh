
#pragma once

#include "scene-object.hh"
#include "vector3.hh"

class Sphere : public SceneObject {
private:

  float m_radius;

public:

  Sphere( Vector3 const&, Material const&, float );

  bool has_hit( const Vector3&, const Vector3&, float* ) const;
  float luminance( const Vector3&, const Vector3& ) const;
  Vector3 normal( const Vector3& ) const;
};

