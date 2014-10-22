
#include <SDL/SDL.h>

#include <iostream>
#include <vector>
#include <sstream>

#include "application.hh"
#include "camera.hh"
#include "window.hh"
#include "scene.hh"

using namespace std;

const int Application::XRES = 800;
const int Application::YRES = 600;

Application::Application( int argc, char ** argv ) : m_camera( XRES, YRES ) {
}

int Application::main() {

  char buffer[1024];
  int buflen;
  int start = 0;
  int end   = 0;

  if( !m_window.open( 800, 600, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  Scene scene;
  scene.build();

  m_camera.position( 0, 0, 0);
  m_camera.direction( 0, 0 ); 

  while( m_window.active() ) {

    buflen = snprintf( buffer, 1024, "%.3f FPS", (1.0 / float(end - start )) * 1000.0);
    m_window.puts( 790 - buflen * 8, 10, buffer );

    m_window.puts( 10, 580, "F1:HELP  F12:QUIT" );
    m_window.tick();

    if( m_window.m_keys[Window::K_UP] )    m_camera.move(  0.5 );
    if( m_window.m_keys[Window::K_DOWN] )  m_camera.move( -0.5 );
    if( m_window.m_keys[Window::K_LEFT] )  m_camera.turn(  0.1 );
    if( m_window.m_keys[Window::K_RIGHT] ) m_camera.turn( -0.1 );
    
    start = SDL_GetTicks();
    m_camera.raytrace( m_window, scene );
    end = SDL_GetTicks();
  }
  
  return 0;
}

