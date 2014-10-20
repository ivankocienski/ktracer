
#pragma once

#include "scene-object.hh"

class Sky : public SceneObject {
private:
public:

  Sky();

  bool has_hit( const Vector3&, const Vector3&, float* ) const;
  float luminance( const Vector3&, const Vector3& ) const;
  Vector3 normal( const Vector3& ) const;
};

