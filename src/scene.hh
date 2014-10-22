
#pragma once

#include <vector>

#include "ray.hh"
#include "scene-object.hh"


class Scene {
private:

  typedef std::vector< SCENE_OBJECT_PTR > scene_object_vector_t;

  scene_object_vector_t m_objects;

  Vector3 m_light_dir;

public:

  Scene();

  void build();
  
  RayHit outline( const Ray& );
  RayHit trace( const Ray& );
  RayHit trace( const Ray&, int, SCENE_OBJECT_PTR );
};

