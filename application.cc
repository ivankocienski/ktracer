
#include <iostream>
#include <vector>
#include <sstream>

#include "application.hh"
#include "camera.hh"
#include "window.hh"
#include "film.hh"
#include "sphere.hh"
#include "plane.hh"

using namespace std;

Application::Application( int argc, char ** argv ) {
}

int Application::main() {

  // we need a scene.

  if( !m_window.open( 800, 600, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  m_camera.position( 0, 0, 0 );
  m_camera.direction( 0, 0 );
  
  Film film( m_window.width(), m_window.height() );

  vector<Sphere> spheres;

  spheres.push_back(Sphere( Vector3(  0.5, 0, -11.5 ), 1 ));
  spheres.push_back(Sphere( Vector3( -0.5, 0, -10.5 ), 1 ));

  Plane plane( Vector3( 0, -1, 0 ), Vector3( 0, 1, 0 ) );

  Vector3 light( 0.2, 0.7, 0.3 );
  light.normalize();

  m_camera.raytrace( film, spheres, plane, light );

  m_window.show( film ); 

  while( m_window.active() ) {
    int x = m_window.mouse_x();
    int y = m_window.mouse_y();
    float d = m_camera.z_at( x, y );

    stringstream s;

    s << "x=" << x << "  y=" << y << "  d=" << d;

    m_window.set_title( s.str().c_str() );

    m_window.tick();
  }
  
  return 0;
}

