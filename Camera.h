#pragma once
#include "stdafx.h"
#include "SaltyEngineIncludes.h"

class Camera
{

public:
	Vec3 lookingTo;
	std::string cameraName;

	Camera& operator=(const Camera&);
	Camera(const Camera& rhs);

	Camera();
	~Camera();
};
