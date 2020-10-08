// $Id: vec3.hh,v 1.1 2009/01/25 11:58:14 jsr Exp jsr $

#ifndef cavlib_vector_hh
#define cavlib_vector_hh

// Define the Vec3 class

// A Vec3 is a vector in three-space. The implementation is all in
// this header file and therefore will be *inlined* for efficiency by
// the compiler (if it can...)

#include <cmath>
#include <iostream>

namespace cav {  

class Vec3
{
private:

  // The only data needed are three double precision values x,y,z:

  double m_x[3];
  
public:
  
  // Construction from x y z values:
  
  Vec3( double x, double y, double z )
  {
    m_x[0] = x;
    m_x[1] = y;
    m_x[2] = z;
  }

  // Allow empty constructor:

  Vec3( ) 
  {
    m_x[0] = 0.0;
    m_x[1] = 0.0;
    m_x[2] = 0.0;
  }

  // Destruction: this is not necessary for this class, but we provide
  // an empty destructor anyway as an example

  ~Vec3() {}

  // assignment of one vector to another:
  
  Vec3& operator=( const Vec3& t )
  {
    m_x[0] = t.x();
    m_x[1] = t.y();
    m_x[2] = t.z();
    return *this;
  }
  
  // copy constructor: 
  
  Vec3( const Vec3& t ) { *this = t; }
  
  // Data access
  
  // x() y() z() are const, so cannot be used to modify the values:
  
  double x() const { return m_x[0]; }
  double y() const { return m_x[1]; }
  double z() const { return m_x[2]; }
  
  // ... but one can change values via [] which returns a reference.
  // Note - no bounds checking is done.
  
  double& operator[]( int i ) { return m_x[i]; }
  
  // Length of vectors:
  
  double len2() const 
  { 
    return m_x[0] * m_x[0] + m_x[1] * m_x[1] + m_x[2] * m_x[2];
  }
  
  double len()  const { return sqrt( len2() ); }
  
  // Output:
  
  void print( std::ostream& os ) const
  {
    os << "(" << m_x[0] << ", " << m_x[1] << ", " << m_x[2] << ")";
  }
  
  // Normalisation, in place:
  
  Vec3& normalise() { return *this /= len(); }
  
  // Unary operators:
  
  Vec3& operator/=( double f )
  {
    m_x[0] /= f;
    m_x[1] /= f;
    m_x[2] /= f;
    return *this;
  }
  
  Vec3& operator*=( double f )
  {
    m_x[0] *= f;
    m_x[1] *= f;
    m_x[2] *= f;
    return *this;
  }
  
  Vec3& operator+=( const Vec3& v )
  {
    m_x[0] += v.x();
    m_x[1] += v.y();
    m_x[2] += v.z();
    return *this;
  }
  
  Vec3& operator-=( const Vec3& v )
  {
    m_x[0] -= v.x();
    m_x[1] -= v.y();
    m_x[2] -= v.z();
    return *this;
  }
  
};  // end of Vec3 class 

// I/O of Vec3 objects:

inline std::ostream& operator<<( std::ostream& os, const Vec3& a )
{
  a.print( os );
  return os;
}

// Inline non-member function utilities for Vec3 objects:

// unary minus negates the vector: 

inline Vec3 operator-( const Vec3& v )
{
  return Vec3( -v.x(), -v.y(), -v.z() );
}

// Addition of vectors:

inline Vec3 operator+( const Vec3& v1, const Vec3& v2 )
{
  return Vec3( v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() );
}

// Subtraction:

inline Vec3 operator-( const Vec3& v1, const Vec3& v2 )
{
  return Vec3( v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z() );
}

// Scaling:

inline Vec3 operator*( const Vec3& v, double f )
{
  return Vec3( f * v.x(), f * v.y(), f * v.z() );
}

inline Vec3 operator*( double f, const Vec3& v )
{
  return Vec3( f * v.x(), f * v.y(), f * v.z() );
}

inline Vec3 operator/( const Vec3& v, double f )
{
  return Vec3( v.x() / f, v.y() / f, v.z() / f );
}

// inner ("dot") product: v1 % v2

inline double operator%( const Vec3& v1, const Vec3& v2 )
{
  return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

// cross product:  v1 * v2

inline Vec3 operator*( const Vec3& v1, const Vec3& v2 )
{
  return Vec3( v1.y() * v2.z() - v1.z() * v2.y(),
	       v1.z() * v2.x() - v1.x() * v2.z(),
	       v1.x() * v2.y() - v1.y() * v2.x() );
}

// Return a normalised vector:

inline Vec3 normalise(  const Vec3& v )
{
  return v / v.len();
}

// Rotate a vector r *clockwise* about given axis by angle phi:

inline Vec3 rotate( const Vec3& r, const Vec3& rotation_axis, double phi )
{
  Vec3 n_hat = normalise( rotation_axis );
  
  return r * cos( phi ) + 
    ( ( (n_hat % r ) * ( 1 - cos(phi) ) ) * n_hat ) -
    ( ( r * n_hat ) * sin(phi) );
}

} // end namespace cav

#endif

