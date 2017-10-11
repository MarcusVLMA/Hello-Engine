#ifndef SALTY_ENGINE_CAMERA_CLASS_H__
#define SALTY_ENGINE_CAMERA_CLASS_H__

#include "Vec3.h"

class Camera {
	Vec3 lookingTo; //Where the camera is looking
	Vec3 position; //Position of the camera 
	unsigned int cameraID; //ID to identify the camera 

public:
	Camera();
	Camera(float xLookingTo, float yLookingTo, float zLookingTo,
		float xPosition, float yPosition, float zPosition,
		unsigned int pcameraID);
	~Camera();

	Camera(const Camera& rhs);
	Camera& operator=(const Camera&);

	void setLookingTo(const Vec3& v);
	Vec3 getLookingTo() const; //Get the coordinate where the camera is looking	
	
	Vec3 getPosition() const; //Get the position coordinate of the camera

	unsigned int getCameraID() const; //Get the cameraID

	void lookTo(float lookToX, float lookToY, float lookToZ); //Make the camera look to coordinate given by parameters
	void moveTo(float moveToX, float moveToY, float moveToZ); //Move the camera to the coordinate given by parameters
	void move(float addX, float addY, float addZ); //Add the especified value to the current coordinate value
	void setCameraID(unsigned pcameraID); //Set the cameraID to the especified value given by parameter
};

#endif /*SALTY_ENGINE_CAMERA_CLASS_H__*/

