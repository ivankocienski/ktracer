
#pragma once

#include <boost/shared_ptr.hpp>

#include "vector3.hh"
#include "material.hh"

class SceneObject {
protected:

  Material m_material;
  Vector3 m_position;

public:

  SceneObject( const Vector3&, const Material& );

  virtual bool has_hit( const Vector3&, const Vector3&, float* ) const;
  virtual float luminance( const Vector3&, const Vector3& ) const;
  virtual Vector3 normal( const Vector3& ) const;

  const Material& material() const;
};

#define SCENE_OBJECT_PTR boost::shared_ptr<SceneObject>
