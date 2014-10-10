
#pragma once

#include <SDL/SDL.h>

class Window {
private:

  SDL_Surface *m_screen;
  bool m_active;
  

public:

  Window();
  ~Window();

  bool open( int, int, const char * );
  
  void clear();
  int width();
  int height();

  void lock();
  void unlock();
  void plot( int, int, unsigned char );

  bool active();
  void tick(); 
};

