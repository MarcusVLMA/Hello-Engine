#ifndef Vec3_CLASS_H
#define Vec3_CLASS_H

#include <cmath>

/// Trasformar em Vec3
class Vec3
{
public:
	Vec3()
	 : x(0), y(0), z(0) 
	{}
	Vec3( float X, float Y, float Z )
	 : x(X), y(Y), z(Z)
	{}
	
	float length() const
	{
		return sqrt(x*x + y*y); // sem usar Z
	}

	float distance2( const Vec3& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return dx*dx + dy*dy;
	}
	
	float distance( const Vec3& v ) const
	{
		const float dx = x - v.x;
		const float dy = y - v.y;

		return sqrt(dx*dx + dy*dy);
	}
	
	Vec3& normalize()
	{
		return (*this) /= sqrt(x*x + y*y);
	}	

	Vec3& operator /=(float f)
	{
		x /= f;
		y /= f;
		z /= f;

		return *this;
	}
	
	Vec3 operator *(float f) const
	{
		return Vec3( x*f, y*f, z*f );
	}
	friend Vec3 operator *(float f, const Vec3& v)
	{
		return Vec3( v.x*f, v.y*f, v.z*f );
	}
	Vec3 operator+(const Vec3& v) const
	{
		return Vec3( x + v.x, y + v.y, 0 );
	}
	Vec3& operator+=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		
		return *this;
	}
	
	Vec3 operator-(const Vec3& v) const
	{
		return Vec3( x - v.x, y - v.y, 0 );
	}

	float x, y, z;
};




#endif

