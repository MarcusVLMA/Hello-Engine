#ifndef SALTY_ENGINE_VEC3_CLASS_H__
#define SALTY_ENGINE_VEC3_CLASS_H__

#pragma once

#include <cmath>
#include <vector>

namespace salty
{

	/** @brief Documente isso!!!!
	 */
	class Vec3
	{
	public:
		Vec3()
			: x(0), y(0), z(0)
		{}
		Vec3(float xx, float yy, float zz = 0.0f)
			: x(xx), y(yy), z(zz)
		{}

		float length() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		float distance2(const Vec3& v) const
		{
			const float dx = x - v.x;
			const float dy = y - v.y;
			const float dz = y - v.y;

			return dx*dx + dy*dy + dz*dz;
		}

		float distance(const Vec3& v) const
		{
			const float dx = x - v.x;
			const float dy = y - v.y;
			const float dz = y - v.y;

			return sqrt(dx*dx + dy*dy + dz*dz);
		}

		Vec3& normalize()
		{
			return (*this) /= sqrt(x*x + y*y + z*z);
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
			return Vec3(x*f, y*f, z*f);
		}
		friend Vec3 operator *(float f, const Vec3& v)
		{
			return Vec3(v.x*f, v.y*f, v.z*f);
		}
		Vec3 operator+(const Vec3& v) const
		{
			return Vec3(x + v.x, y + v.y, z + v.z);
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
			return Vec3(x - v.x, y - v.y, z - v.z);
		}

		float x, y, z;
	};

	typedef std::vector<Vec3> Vec3Vector;
}

#endif /* SALTY_ENGINE_VEC3_CLASS_H__ */

