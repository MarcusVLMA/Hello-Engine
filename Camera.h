#pragma once
#ifndef SALTY_ENGINE_CAMERA_CLASS_H__
#define SALTY_ENGINE_CAMERA_CLASS_H__

#include "stdafx.h"
#include "Vec3.h"
#include "Scene.h"
#include "POV.h"
#include "Named.h"

namespace salty
{

	class Camera : public Named {
		Scene*		 scene;	   //Scene that contains the POV that the Camera is looking
		POV*		 pov;	   //Pov that the Camera is looking
		Vec3		 position; //Position of the camera
		unsigned int cameraID; //ID to identify the camera

	public:
		Camera();
		Camera(Scene* pscene, POV* ppov,
			   float xPosition, float yPosition, float zPosition,
			   unsigned int pcameraID);
		~Camera();

		Camera(const Camera& rhs);
		Camera& operator=(const Camera&);

		Scene*		 getScene()	   const; //Get the scene that the camera is looking
		const Vec3&  getPosition() const; //Get the position coordinate of the camera
		const POV*   getPov()	   const; //Get the pov that the camera is looking
		unsigned int getCameraID() const; //Get the cameraID
		
		void setPov		(POV* ppov);								   //Set the pov that the camera looks
		void setScene	(Scene* pscene);							   //Set the scene that the camera looks
		void moveTo		(float moveToX, float moveToY, float moveToZ); //Move the camera to the coordinate given by parameters
		void move		(float addX, float addY, float addZ);		   //Add the especified value to the current coordinate value
		void setCameraID(unsigned pcameraID);						   //Set the cameraID to the especified value given by parameter
	};
}
#endif /*SALTY_ENGINE_CAMERA_CLASS_H__*/

