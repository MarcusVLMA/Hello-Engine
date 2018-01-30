#ifndef SALTY_ENGINE_POV_CLASS_H__
#define SALTY_ENGINE_POV_CLASS_H__
#pragma once

#include "stdafx.h"
#include "Vec3.h"

namespace salty
{

	class POV {
		Vec3 position;
		Vec3 velocity;
		unsigned int povID;

	public:
		POV(float xPosition, float yPosition, unsigned int pPovID);
		POV(const Vec3& pPosition, const Vec3& pVelocity, unsigned int pPovID);
		~POV();

		Vec3 getPosition()      const;
		Vec3 getVelocity()      const;
		unsigned int getPovID() const;

		void setPosition(float xposition, float yposition, float zposition);
		void setVelocity(float xvelocity, float yvelocity, float zvelocity);
		void setPovID   (unsigned int pPovID);
	};

}

#endif