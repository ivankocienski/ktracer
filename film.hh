
#pragma once

#include <vector>

class Film {
public:

  typedef unsigned char pixel_t;

private:

  int m_width;
  int m_height;

  std::vector<pixel_t> m_pixels;

public:

  Film( int, int );

  int width();
  int height();

  void plot( int, int, pixel_t );
  pixel_t pget( int, int ); 
};

