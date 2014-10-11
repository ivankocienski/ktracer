
#include <iostream>

#include <math.h>

#include "vector3.hh"

Vector3::Vector3() {
  x = 0;
  y = 0;
  z = 0;
}

Vector3::Vector3( float _x, float _y, float _z ) {
  x = _x;
  y = _y;
  z = _z;
};

float Vector3::magnitude() {
  return sqrt( x * x + y * y + z * z );
}

void Vector3::normalize() {
  float m = magnitude();

  x /= m;
  y /= m;
  z /= m; 
}

void Vector3::invert() {
  x = -x;
  y = -y;
  z = -z;
}

void Vector3::operator*=( float q ) {

  x *= q;
  y *= q;
  z *= q; 
}

void Vector3::operator+=( float q ) {

  x += q;
  y += q;
  z += q; 
}

Vector3 Vector3::cross( const Vector3 &v ) {

  Vector3 nv;

  nv.x = y * v.z - z * v.y;
  nv.y = z * v.x - x * v.z;
  nv.z = x * v.y - y * v.x;

  return nv;
}

void Vector3::dump() {
  std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
}
