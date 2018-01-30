#include "stdafx.h"
#include "MoveLeft.h"


MoveLeft::MoveLeft()
{
}


MoveLeft::~MoveLeft()
{
}

void MoveLeft::execute(salty::SceneActor& psceneActor) {
	psceneActor.setPositionX(psceneActor.getPosition().x - psceneActor.getSpeed().x);
}
