
#pragma once

#include <SDL/SDL.h>
#include <list>

#include "film.hh"

class Window {
public:

  enum {
    K_NULL,
    K_UP,
    K_DOWN,
    K_RIGHT,
    K_LEFT  
  };

private:

  SDL_Surface *m_screen;
  bool m_active;

  std::list<int> m_keys;

  int m_mouse_x;
  int m_mouse_y;

public:

  Window();
  ~Window();

  bool open( int, int, const char * );
  void set_title( const char * );
  
  void clear();
  int width();
  int height();

  void show( Film& );

  bool active();
  void tick(); 

  int mouse_x();
  int mouse_y();

  int get_next_key();
};

