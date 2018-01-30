#include "stdafx.h"
#include "MoveRight.h"


MoveRight::MoveRight()
{
}


MoveRight::~MoveRight()
{
}


void MoveRight::execute(salty::SceneActor& psceneActor) {
	psceneActor.setPositionX(psceneActor.getPosition().x + psceneActor.getSpeed().x);
}