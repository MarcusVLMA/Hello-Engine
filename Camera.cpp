#include "stdafx.h"
#include "Camera.h"
namespace salty
{
Camera::Camera()
	: position(0, 0, 0),
	  cameraID(0)
{
	scene = nullptr;
	pov = nullptr;
}
//--------------------------------------------------------------------------------------------------------------------
Camera::Camera(Scene* pscene, POV* ppov, float xPosition, float yPosition, float zPosition, unsigned int pcameraID)
	: position(xPosition, yPosition, zPosition),
	  cameraID(pcameraID)
{
	scene = pscene;
	pov = ppov;
}
//--------------------------------------------------------------------------------------------------------------------
Camera::~Camera() {

}
//--------------------------------------------------------------------------------------------------------------------
Camera::Camera(const Camera& rhs)
	: position(rhs.position),
	  cameraID(rhs.cameraID)
{
	scene = rhs.scene;
	pov = rhs.pov;
}
//--------------------------------------------------------------------------------------------------------------------
Camera& Camera::operator=(const Camera&) {
	return *this;
}
//--------------------------------------------------------------------------------------------------------------------
Scene* Camera::getScene() const {
	return scene;
}
//--------------------------------------------------------------------------------------------------------------------
const POV* Camera::getPov() const {
	return pov;
}
//--------------------------------------------------------------------------------------------------------------------
const Vec3& Camera::getPosition() const {
	return position;
}

//--------------------------------------------------------------------------------------------------------------------
unsigned int Camera::getCameraID() const {
	return cameraID;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::setPov(POV* ppov) {
	pov = ppov;
}
//--------------------------------------------------------------------------------------------------------------------
void Camera::setScene(Scene* pscene) {
	scene = pscene;
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
}
