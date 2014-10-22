
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
  m_app_mode = AM_DETAIL_VIEW;
}

int Application::main() {

  if( !m_window.open( XRES, YRES, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  m_scene.build();

  m_camera.position( 0, 0, 0);
  m_camera.direction( 0, 0 ); 

  while( m_window.active() ) {
    
    switch( m_app_mode ) {
      case AM_DETAIL_VIEW: do_detail_view(); break;
      case AM_FAST_VIEW: do_fast_view(); break;
      case AM_HELP: do_help(); break;
    }
  }
  
  return 0;
}

void Application::do_detail_view() {

  char buffer[1024];
  int buflen;
  int start = 0;
  int end   = 0;

  while( m_window.active() ) {

    buflen = snprintf( buffer, 1024, "%.3f FPS", (1.0 / float(end - start )) * 1000.0);
    m_window.puts( 790 - buflen * 8, 10, buffer );

    m_window.puts( 10, 580, "F1:HELP  F12:QUIT" );
    m_window.tick();

    if( m_window.m_keys[Window::K_UP] )    m_camera.move(  0.5 );
    if( m_window.m_keys[Window::K_DOWN] )  m_camera.move( -0.5 );
    if( m_window.m_keys[Window::K_LEFT] )  m_camera.turn(  0.1 );
    if( m_window.m_keys[Window::K_RIGHT] ) m_camera.turn( -0.1 );
    
    while( int key = m_window.inkey() ) {
      switch( key ) {
        case Window::K_F1:
          m_app_mode = AM_HELP;
          return;
          break;
      }
    }

    start = SDL_GetTicks();
    m_camera.raytrace( m_window, m_scene );
    end = SDL_GetTicks();
  }
}

void Application::do_fast_view() {

}

void Application::do_help() {

  m_window.clear();
  m_window.flush_keys();

  m_window.puts( 10, 10, "yes, this is help" );


  while( m_window.active() ) {

    m_window.tick();

    while( int key = m_window.inkey() ) {
      switch(key) {
        case Window::K_ESCAPE:
          m_app_mode = AM_DETAIL_VIEW;
          return;
          break;
      }
    }
  }

}
