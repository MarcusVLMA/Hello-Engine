#include "stdafx.h"
#include "MoveDown.h"


MoveDown::MoveDown()
{
}


MoveDown::~MoveDown()
{
}

void MoveDown::execute(salty::SceneActor& psceneActor) {
	psceneActor.setPositionY(psceneActor.getPosition().y - psceneActor.getSpeed().y);
}