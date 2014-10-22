
#pragma once

#include "window.hh"
#include "camera.hh"

class Application {
private:

  static const int XRES;
  static const int YRES;

  Window m_window;
  Camera m_camera;

public:
  
  Application( int, char** );

  int main();
};

