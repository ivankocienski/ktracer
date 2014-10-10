
#include <iostream>

#include "application.hh"

using namespace std;

Application::Application( int argc, char ** argv ) {
}

int Application::main() {

  if( !m_window.open( 800, 600, "ktracer demo" )) {
    cerr << "could not open window" << endl;
    return -1;
  }

  m_window.clear();
  m_window.lock();

  for( int y = 0; y < m_window.height(); y++)
    for( int x = 0; x < m_window.width(); x++ )
      m_window.plot( x, y, x ^ y );

  m_window.unlock();

  while( m_window.active() ) {
    m_window.tick();
  }
  
  return 0;
}

