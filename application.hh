
#pragma once

#include "window.hh"
#include "camera.hh"

class Application {
private:

  Window m_window;
  Camera m_camera;

public:
  
  Application( int, char** );

  int main();
};

