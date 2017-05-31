#include "stdafx.h"
#include "SaltyEngineIncludes.h"
Camera::Camera(){
	
}
Camera::Camera( const Camera& rhs )
	: lookingTo(rhs.lookingTo), cameraName(rhs.cameraName)
{
}

Camera& Camera::operator=(const Camera&)
{
return *this;
}
