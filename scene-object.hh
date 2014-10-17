
#pragma once

#include <boost/shared_ptr.hpp>

#include "vector3.hh"

class SceneObject {
private:

public:

  SceneObject();

  virtual bool has_hit( const Vector3&, const Vector3&, float* );
  virtual float luminance( const Vector3&, const Vector3& );
};

#define SCENE_OBJECT_PTR boost::shared_ptr<SceneObject>
