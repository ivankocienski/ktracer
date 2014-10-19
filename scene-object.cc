
#include "scene-object.hh"

SceneObject::SceneObject( const Vector3& p, const Material& m ) {
  m_position = p;
  m_material = m;
}

bool SceneObject::has_hit( const Vector3&, const Vector3&, float* ) const {
  return false; 
}

float SceneObject::luminance( const Vector3&, const Vector3& ) const {
  return 0;
}

Vector3 SceneObject::normal( const Vector3& h ) const {
  return Vector3( 1, 0, 0 );
}

const Material& SceneObject::material() const {
  return m_material;
}
