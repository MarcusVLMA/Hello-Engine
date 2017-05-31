// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngineIncludes.h"

SaltyEngine engine;
Sprite *sonic;
Camera *camera;

int main(int argc, char **argv)
{	
	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	sonic = engine.createSprite("sonic.png", 0);
	camera = engine.createCamera("Minha Camera", 0, 0, 0, sonic);
	engine.loop();

	return 0;
	/*engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	
	engine.setTexture(sonic, "sonic.png", 0);
	glutDisplayFunc(Draw);
	engine.loop();*/
}

