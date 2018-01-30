#pragma once
#include "stdafx.h"
#include "Command.h"
class MoveUp : Command
{
public:
	MoveUp();
	~MoveUp();
	void execute(salty::SceneActor& psceneActor);
};

