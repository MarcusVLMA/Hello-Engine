#include "POV.h"

POV::POV(float xPosition, float yPosition, unsigned int pPovID) {
	
	position.x = xPosition;
	position.y = yPosition;
	position.z = 0.0f;

	velocity.x = 0.0f;
	velocity.y = 0.0f;
	velocity.z = 0.0f;

	povID = pPovID;
}

POV::POV(Vec3 pPosition, Vec3 pVelocity, unsigned int pPovID) {
	position = pPosition;
	velocity = pVelocity;
	povID = pPovID;
}
// ------------------------------------------------------------------------------------

POV::~POV() {

}

// ------------------------------------------------------------------------------------

Vec3 POV::getPosition() const {
	return position;
}

// ------------------------------------------------------------------------------------

Vec3 POV::getVelocity() const {
	return velocity;
}

// ------------------------------------------------------------------------------------

unsigned int POV::getPovID() const {
	return povID;
}

// ------------------------------------------------------------------------------------

void POV::setPosition(float xposition, float yposition, float zposition) {
	position.x = xposition;
	position.y = yposition;
	position.z = zposition;
}

// ------------------------------------------------------------------------------------

void POV::setVelocity(float xvelocity, float yvelocity, float zvelocity) {
	velocity.x = xvelocity;
	velocity.y = yvelocity;
	velocity.z = zvelocity;
}

// ------------------------------------------------------------------------------------

void POV::setPovID(unsigned int pPovID) {
	povID = pPovID;
}