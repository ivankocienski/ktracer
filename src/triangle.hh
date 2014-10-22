
#pragma once

#include "scene-object.hh"

class Triangle : public SceneObject {
private:

  Vector3 m_a;
  Vector3 m_b;
  Vector3 m_c;
  Vector3 m_normal;

  Vector3 m_e1;
  Vector3 m_e2;

public:
  
  Triangle( const Vector3&, const Vector3&, const Vector3&, const Material& );

  bool has_hit( const Vector3&, const Vector3&, float* ) const;
  float luminance( const Vector3&, const Vector3& ) const;
  Vector3 normal( const Vector3& ) const;
};

