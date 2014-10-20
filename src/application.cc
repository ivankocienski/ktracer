
#include <iostream>
#include <vector>
#include <sstream>

#include "application.hh"
#include "camera.hh"
#include "window.hh"
#include "scene.hh"
#include "film.hh"

using namespace std;

Application::Application( int argc, char ** argv ) {
}

int Application::main() {

  if( !m_window.open( 800, 600, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  Film film( m_window.width(), m_window.height() );

  Scene scene;
  scene.build();

  m_camera.position( 0, 0, 0 );
  m_camera.direction( 0, 0 ); 
  m_camera.raytrace( film, scene );

  m_window.show( film ); 

  while( m_window.active() ) {
    m_window.tick();
  }
  
  return 0;
}

