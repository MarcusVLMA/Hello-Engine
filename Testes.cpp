// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngine.h"

#include <iostream>

SaltyEngine engine;
Sprite *sonic;


int main(int argc, char **argv)
{
	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	
	sonic = engine.createSprite( "sonic.png", 0);
	sonic->angle = 45;	
	engine.loop();
	
	return 0;
}

