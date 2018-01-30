#pragma once
#include "stdafx.h"
#include "SceneActor.h"

class Command {

public:
	virtual ~Command() {};
	virtual void execute(salty::SceneActor& psceneActor) = 0;
};