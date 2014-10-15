
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

void Window::set_title( const char *t ) {
  SDL_WM_SetCaption( t, 0 );
}

int Window::width() {
  return m_screen->w;
}

int Window::height() {
  return m_screen->h;
}

void Window::show( Film &film ) {

  int fw;
  int fh;
  int fxo = 0;
  int fyo = 0;
  int sxo = 0;
  int syo = 0;
  int x;
  int y;

  fw = film.width();
  fh = film.height();

  if(fw > m_screen->w) {
    fw  = m_screen->w;
    fxo = (film.width() - fw) / 2;

  } else {
    sxo = (m_screen->w - fw) / 2;
  }

  if(fh > m_screen->h) {
    fh = m_screen->h;
    fyo = (film.height() - fh) / 2; 

  } else {
    syo = (m_screen->h - fh) / 2;
  }

  SDL_LockSurface(m_screen);

  unsigned char *vbuff = (unsigned char *)m_screen->pixels;

  vbuff += syo * m_screen->pitch + sxo;

  for( y = syo; y < fh; y++ ) {
    for( x = sxo; x < fw; x++ ) {

      *vbuff = film.pget( fxo + x, fyo + y );

      vbuff++; 
    }

    vbuff += m_screen->pitch - fw;
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
