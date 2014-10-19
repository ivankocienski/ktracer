
#include <float.h>

#include "debug.h"

#include "scene.hh"

#include "vector3.hh"
#include "sphere.hh"
#include "plane.hh"

Scene::Scene() {}

void Scene::build() {

  {
    Material sphere_mat;
    Sphere *sphere;
    
    sphere_mat.m_reflectance = 1;

    sphere = new Sphere( Vector3(  0.5, 0, -11.5 ), sphere_mat, 1 );
    m_objects.push_back( SCENE_OBJECT_PTR( sphere ));

    sphere = new Sphere( Vector3( -0.5, 0, -10.5 ), sphere_mat, 1 );
    m_objects.push_back( SCENE_OBJECT_PTR( sphere ));
  }


  {
    Material plane_mat;
    Plane *plane;

    plane = new Plane( Vector3( 0, -1.5, 0 ), plane_mat, Vector3( 0, 1, 0 ) );
    m_objects.push_back( SCENE_OBJECT_PTR( plane ));
  }

  m_light_dir = Vector3( 0.2, 0.7, 0.3 );
  m_light_dir.normalize();

  cout << "scene has " << m_objects.size() << " objects defined" << endl;
}

RayHit Scene::trace( const Ray& ray, int bounce ) {

  float dist = FLT_MAX;
  float lum = 0;
  float d;
  scene_object_vector_t::iterator it;

  for( it = m_objects.begin(); it != m_objects.end(); it++ ) {

    SCENE_OBJECT_PTR obj = *it;

    if( !obj->has_hit( ray.m_position, ray.m_direction, &d )) continue;

    if( d >= dist ) continue;

    Vector3 hit = ray.m_position + (ray.m_direction * d);

    if( obj->material().m_reflectance > 0 && bounce ) {

      RayHit bounce_hit = trace( ray.reflect( d, obj->normal(hit) ), bounce - 1 ); 

      // ignore distance as this is not a primary ray.

      // todo: proper fresnel mixing
      lum = bounce_hit.m_luminance;

    } else {

      lum  = obj->luminance( hit, m_light_dir );
    }

    dist = d;
  }

  if( dist <  1 ) return RayHit( FLT_MAX, 0 );
  if( dist > 25 ) return RayHit( FLT_MAX, 0 );

  lum = (float)lum * (1.0 - (dist / 25.0));

  return RayHit( dist, lum );
}

RayHit Scene::trace( const Ray& ray ) {
  return trace( ray, 3 );
}
