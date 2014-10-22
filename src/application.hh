
#pragma once

#include "window.hh"
#include "camera.hh"
#include "scene.hh"

class Application {
private:

  static const int XRES;
  static const int YRES;

  enum app_mode {
    AM_DETAIL_VIEW,
    AM_FAST_VIEW,
    AM_HELP
  };

  app_mode m_app_mode;
  
  Window m_window;
  Camera m_camera;
  Scene  m_scene;

  void do_detail_view();
  void do_fast_view();
  void do_help();
    

public:
  
  Application( int, char** );

  int main();
};

