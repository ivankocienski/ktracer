
#include <iostream>

#include "application.hh"
#include "camera.hh"
#include "window.hh"
#include "film.hh"
#include "sphere.hh"

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

  Sphere sphere( Vector3( 0, 0, -10.5 ), 1 );

  m_camera.raytrace( film, sphere );
  m_window.show( film ); 

  while( m_window.active() ) {
    m_window.tick();
  }
  
  return 0;
}

