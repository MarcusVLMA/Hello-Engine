#include "stdafx.h"
#include "MoveUp.h"


MoveUp::MoveUp()
{
}


MoveUp::~MoveUp()
{
}

void MoveUp::execute(salty::SceneActor& psceneActor) {
	psceneActor.setPositionY(psceneActor.getPosition().y + psceneActor.getSpeed().y);
}