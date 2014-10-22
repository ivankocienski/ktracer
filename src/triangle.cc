
#include "triangle.hh"

#define EPSILON 1e-6

Triangle::Triangle( const Vector3& p1, const Vector3& p2, const Vector3& p3, const Material& m ) : SceneObject( p1, m ) {

  m_a = p1;
  m_b = p2;
  m_c = p3;

  m_e1 = m_b - m_a;
  m_e2 = m_c - m_a;

  m_normal = m_e1.cross(m_e2);
  m_normal.normalize();
}

bool Triangle::has_hit( const Vector3& ray_pos, const Vector3& ray_dir, float *d ) const {

  float u, v;

  Vector3 pvec = ray_dir.cross(m_e2);

  float det = m_e1.dot( pvec );

  // hit the back side / is parallel to us
  if (det < EPSILON) return false;

  float invDet = 1 / det;

  // prepare to compute u
  Vector3 tvec = ray_pos - m_a;
  u = tvec.dot(pvec) * invDet;
  if (u < 0 || u > 1) return false;

  // prepare to compute v
  Vector3 qvec = tvec.cross( m_e1 );
  v = ray_dir.dot(qvec) * invDet;
  if (v < 0 || v > 1 || u + v > 1) return false;

  // calculate t, ray intersects triangle
  //t = dot(e2, qvec) * invDet;

  // hmm- how do we store these? 
  //   how do we calculate the hit point?

  *d = 10;

  return true; 
}

float Triangle::luminance( const Vector3&, const Vector3& ) const {

  return 0.4;
}

Vector3 Triangle::normal( const Vector3& ) const {
  return m_normal; 
}

