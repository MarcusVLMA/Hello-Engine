#pragma once
#include "stdafx.h"
#include "Command.h"

class MoveLeft : Command
{
public:
	MoveLeft();
	~MoveLeft();

	void execute(salty::SceneActor& psceneActor);
};

