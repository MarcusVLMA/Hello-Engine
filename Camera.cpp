#include "Camera.h"

Camera::Camera()
	: lookingTo(0, 0, 0),
	position(0, 0, 0),
	cameraID(0)
{}
//--------------------------------------------------------------------------------------------------------------------
Camera::Camera(float xLookingTo, float yLookingTo, float zLookingTo, float xPosition, float yPosition, float zPosition, unsigned int pcameraID)
	: lookingTo(xLookingTo, yLookingTo, zLookingTo),
	position(xPosition, yPosition, zPosition),
	cameraID(pcameraID)
{}
//--------------------------------------------------------------------------------------------------------------------
Camera::~Camera() {

}
//--------------------------------------------------------------------------------------------------------------------
Camera::Camera(const Camera& rhs)
	: lookingTo(rhs.lookingTo),
	position(rhs.position),
	cameraID(rhs.cameraID)
{}
//--------------------------------------------------------------------------------------------------------------------
Camera& Camera::operator=(const Camera&) {
	// TODO copiar!
	return *this;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::setLookingTo(const Vec3& v)
{
	lookingTo = v;
}
//--------------------------------------------------------------------------------------------------------------------
Vec3 Camera::getLookingTo() const {
	return lookingTo;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getLookingToX() const {
	return lookingTo.x;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getLookingToY() const {
	return lookingTo.y;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getLookingToZ() const {
	return lookingTo.z;
}
//--------------------------------------------------------------------------------------------------------------------
Vec3 Camera::getPosition() const {
	return position;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getPositionX() const {
	return position.x;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getPositionY() const {
	return position.y;
}
//--------------------------------------------------------------------------------------------------------------------
float Camera::getPositionZ() const {
	return position.z;
}
//--------------------------------------------------------------------------------------------------------------------
unsigned int Camera::getCameraID() const {
	return cameraID;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::lookTo(float lookToX, float lookToY, float lookToZ) {
	lookingTo.x = lookToX;
	lookingTo.y = lookToY;
	lookingTo.z = lookToZ;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::moveTo(float moveToX, float moveToY, float moveToZ) {
	position.x = moveToX;
	position.y = moveToY;
	position.z = moveToZ;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::move(float addX, float addY, float addZ) {
	position.x += addX;
	position.y += addY;
	position.z += addZ;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::setCameraID(unsigned pcameraID) {
	cameraID = pcameraID;
}
//--------------------------------------------------------------------------------------------------------------------
