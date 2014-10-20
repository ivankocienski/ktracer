
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

  bool refresh = true;
  float xpos = 0;
  float ypos = 0;

  if( !m_window.open( 800, 600, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  Film film( m_window.width(), m_window.height() );

  Scene scene;
  scene.build();

  m_camera.position( xpos, 0, ypos );
  m_camera.direction( 0, 0 ); 

  while( m_window.active() ) {
    m_window.tick();

    while( int key = m_window.get_next_key() ) {

      switch( key ) {

        case Window::K_UP:
          m_camera.move( 0.1 );
          refresh = true;
          break;

        case Window::K_DOWN:
          m_camera.move( -0.1 );
          refresh = true;
          break;

        case Window::K_LEFT:
          m_camera.turn( 0.1 );
          refresh = true;
          break;

        case Window::K_RIGHT:
          m_camera.turn( -0.1 );
          refresh = true;
          break;

        default:
          break;
      }
    }
    

    if( refresh ) {
      m_camera.raytrace( film, scene );
      m_window.show( film ); 

      refresh = false;
    }

    
  }
  
  return 0;
}

