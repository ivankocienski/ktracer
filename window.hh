
#pragma once

#include <SDL/SDL.h>

#include "film.hh"

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

  void show( Film& );

  bool active();
  void tick(); 
};

