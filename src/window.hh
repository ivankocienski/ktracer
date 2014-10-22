
#pragma once

#include <SDL/SDL.h>
#include <vector>

class Window {
public:

  enum {
    K_NULL,
    K_UP,
    K_DOWN,
    K_RIGHT,
    K_LEFT,
    K_MAX
  };

private:

  SDL_Surface *m_screen;
  SDL_Surface *m_font;

  bool m_active;

  int m_mouse_x;
  int m_mouse_y;

public:

  bool m_keys[K_MAX];

  Window();
  ~Window();

  bool open( int, int, const char * );
  void set_title( const char * );
  
  void puts( int, int, const char* );

  void clear();
  int width();
  int height();

  void apply_film( std::vector<unsigned char>& );

  bool active();
  void tick(); 

  int mouse_x();
  int mouse_y();

};

