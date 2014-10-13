
#include "film.hh"

#include <vector>

using namespace std;

Film::Film( int w, int h ) {
  m_width  = w;
  m_height = h;
  m_pixels.resize( h * w );
}

void Film::plot( int x, int y, Film::pixel_t c ) {
  if( x < 0 || x >= m_width ) return;
  if( y < 0 || y >= m_height ) return;

  m_pixels[ y * m_width + x ] = c;
}

int Film::width() {
  return m_width;
}

int Film::height() {
  return m_height; 
}

float Film::ratio() {
  return (float)m_width / (float)m_height;
}

Film::pixel_t Film::pget( int x, int y ) {
  if( x < 0 || x >= m_width  ) return 0;
  if( y < 0 || y >= m_height ) return 0;

  return m_pixels[ y * m_width + x]; 
}

