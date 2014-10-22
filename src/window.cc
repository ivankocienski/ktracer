
#include <cstring>

#include "window.hh"
#include <SDL/SDL_image.h>

Window::Window() {
  m_screen = NULL;
  m_active = false;
  memset( m_keys, false, sizeof(m_keys) );
}

Window::~Window() {
  SDL_Quit();
}

bool Window::open( int xr, int yr, const char *t ) {

  if(SDL_Init(SDL_INIT_VIDEO) != 0) return false;

  m_screen = SDL_SetVideoMode( xr, yr, 8, SDL_DOUBLEBUF | SDL_SWSURFACE );
  if(!m_screen) return false;

  SDL_WM_SetCaption( t, 0 );
  
  SDL_Color palette[256];
  int i;

  for( i = 0; i < 256; i++ ) {
    palette[i].r = i;
    palette[i].g = i;
    palette[i].b = i;
  }

  SDL_SetPalette( m_screen, SDL_LOGPAL | SDL_PHYSPAL, palette, 0, 256 );

  m_active = true;

  m_font = IMG_Load( "data/font.png" );
  if( !m_font ) return false;

  //SDL_SetPalette( m_font, SDL_LOGPAL, palette, 0, 256 );

  //SDL_SetAlpha( m_font, SDL_SRCALPHA, 0 );

  return true;
}

void Window::set_title( const char *t ) {
  SDL_WM_SetCaption( t, 0 );
}

int Window::width() {
  return m_screen->w;
}

int Window::height() {
  return m_screen->h;
}

void Window::apply_film( std::vector<unsigned char> &film ) {

  // film has to be the same size as the camera or bad things will happen

  SDL_LockSurface(m_screen);

  unsigned char *vbuff = (unsigned char *)m_screen->pixels;
  unsigned char *sbuff = film.data();

  for( int y = 0; y < m_screen->h; y++ ) {
    memcpy( vbuff, sbuff, m_screen->w );

    vbuff += m_screen->pitch;
    sbuff += m_screen->w;
  }
  
  SDL_UnlockSurface(m_screen); 

}

bool Window::active() {
  return m_active;
}

void Window::clear() {
  SDL_FillRect( m_screen, NULL, 0 );
}

void Window::tick() {

  SDL_Event event;

  SDL_Flip(m_screen);
  SDL_Delay(20);

  while(SDL_PollEvent( &event )) {
    switch( event.type ) {
      case SDL_QUIT:
        m_active = false;
        break;

      case SDL_KEYUP:

        switch( event.key.keysym.sym ) {
          case SDLK_F12:   m_active = false; break;
          case SDLK_UP:    m_keys[K_UP]    = false; break;
          case SDLK_DOWN:  m_keys[K_DOWN]  = false; break;
          case SDLK_LEFT:  m_keys[K_LEFT]  = false; break;
          case SDLK_RIGHT: m_keys[K_RIGHT] = false; break;
          default: break;
        }
        break;

      case SDL_KEYDOWN:
        switch( event.key.keysym.sym ) {
          case SDLK_UP:    m_keys[K_UP]    = true; break;
          case SDLK_DOWN:  m_keys[K_DOWN]  = true; break;
          case SDLK_LEFT:  m_keys[K_LEFT]  = true; break;
          case SDLK_RIGHT: m_keys[K_RIGHT] = true; break;
          default: break;
        }
        break;

      case SDL_MOUSEMOTION:
        m_mouse_x = event.motion.x;
        m_mouse_y = event.motion.y;
        break;
    }
  }
}

int Window::mouse_x() {
  return m_mouse_x;
}

int Window::mouse_y() {
  return m_mouse_y;
}


void Window::puts( int x, int y, const char* t ) {
  SDL_Rect dst = { x, y, 0, 0 };
  SDL_Rect src = { 0, 0, 8, 8 };
  
  char c;

  while( *t ) {
    c = *t - 32;
    src.x = (c & 0x0f) << 3;
    src.y = (c & 0xf0) >> 1;

    SDL_BlitSurface( m_font, &src, m_screen, &dst );

    t++;
    dst.x += 8;
  } 
}
