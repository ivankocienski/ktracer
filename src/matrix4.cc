
#include <cstring>

#include "matrix4.hh"

Matrix4::Matrix4() {
  memset( m_v, 0, sizeof(m_v) );
}
