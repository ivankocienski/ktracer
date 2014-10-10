
#include "window.hh"

Window::Window() {
  m_screen = NULL;
  m_active = false;
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

  return true;
}

int Window::width() {
  return m_screen->w;
}

int Window::height() {
  return m_screen->h;
}

void Window::lock() {
  SDL_LockSurface(m_screen);
}

void Window::unlock() {
  SDL_UnlockSurface(m_screen);
}

void Window::plot( int x, int y, unsigned char c ) {
  if( x < 0 || x >= m_screen->w ) return;
  if( y < 0 || y >= m_screen->h ) return;

  unsigned char *p = (unsigned char *)m_screen->pixels;

  p[ y * m_screen->pitch + x ] = c; 
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
  SDL_Delay(100);

  while(SDL_PollEvent( &event )) {
    switch( event.type ) {
      case SDL_QUIT:
        m_active = false;
        break;

      case SDL_KEYUP:
        if(event.key.keysym.sym == SDLK_F12) {
          m_active = false;

        }
        break;
    }
  }
}

