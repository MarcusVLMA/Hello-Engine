#pragma once
#include "stdafx.h"
#include "SaltyEngineIncludes.h"

class POV {
	Vec3 position;
	Vec3 velocity;
	unsigned int povID;

public:
	POV(float xPosition, float yPosition, unsigned int pPovID);
	POV(Vec3* pPosition, Vec3* pVelocity, unsigned int pPovID);
	~POV();

	Vec3 getPosition()      const;
	Vec3 getVelocity()      const;
	unsigned int getPovID() const;

	void setPosition(float xposition, float yposition, float zposition);
	void setVelocity(float xvelocity, float yvelocity, float zvelocity);
	void setPovID   (unsigned int pPovID);
};