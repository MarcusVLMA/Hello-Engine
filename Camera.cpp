#include "stdafx.h"
#include "SaltyEngineIncludes.h"


Camera::Camera()
	: lookingTo(0, 0, 0), cameraName("camera"), position(0, 0, 1)
{
	
}

Camera::~Camera(){
	
}

Camera::Camera(const Camera& rhs)
	: lookingTo(rhs.lookingTo), cameraName(rhs.cameraName), position(rhs.position)
{
}

Camera& Camera::operator=(const Camera&)
{
	return *this;
}
