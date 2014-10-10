
#pragma once

#include "window.hh"

class Application {
private:

  Window m_window;

public:
  
  Application( int, char** );

  int main();
};

