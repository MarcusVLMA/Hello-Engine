#pragma once
#include "stdafx.h"
#include "Command.h"

class MoveDown : Command
{
public:
	MoveDown();
	~MoveDown();
	void execute(salty::SceneActor& pscene);
};

