
#include "scene-object.hh"

SceneObject::SceneObject() {
}

bool SceneObject::has_hit( const Vector3&, const Vector3&, float* ) {
  return false; 
}

float SceneObject::luminance( const Vector3&, const Vector3& ) {
  return 0;
}

