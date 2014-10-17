
#include <float.h>

#include "scene.hh"

#include "vector3.hh"
#include "sphere.hh"
#include "plane.hh"

Scene::Scene() {}

void Scene::build() {

  m_objects.push_back( SCENE_OBJECT_PTR( new Sphere( Vector3(  0.5, 0, -11.5 ), 1 )));
  m_objects.push_back( SCENE_OBJECT_PTR( new Sphere( Vector3( -0.5, 0, -10.5 ), 1 )));

  m_objects.push_back( SCENE_OBJECT_PTR( new Plane( Vector3( 0, -1.5, 0 ), Vector3( 0, 1, 0 ))));

  m_light_dir = Vector3( 0.2, 0.7, 0.3 );
  m_light_dir.normalize();
}

RayHit Scene::trace( const Ray& ray ) {

  float dist = FLT_MAX;
  float lum = 0;
  float d;
  scene_object_vector_t::iterator it;

  for( it = m_objects.begin(); it != m_objects.end(); it++ ) {

    SCENE_OBJECT_PTR obj = *it;

    if( !obj->has_hit( ray.m_position, ray.m_direction, &d )) continue;

    if( d >= dist ) continue;

    Vector3 hit = ray.m_position + (ray.m_direction * d);

    dist = d;
    lum  = obj->luminance( hit, m_light_dir );
  }

  if( dist <  1 ) return RayHit( FLT_MAX, 0 );
  if( dist > 25 ) return RayHit( FLT_MAX, 0 );

  lum = (float)lum * (1.0 - (dist / 25.0));

  return RayHit( dist, lum );
}
