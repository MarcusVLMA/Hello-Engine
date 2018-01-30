#pragma once
#include "stdafx.h"
#include "Command.h"

class MoveRight : Command
{
public:
	MoveRight();
	~MoveRight();

	void execute(salty::SceneActor& psceneActor);
};

