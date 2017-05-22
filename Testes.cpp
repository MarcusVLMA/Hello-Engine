// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngine.h"

SaltyEngine engine;
Sprite *sonic;

void Draw() {
	
}

int main(int argc, char **argv)
{
	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	
	engine.setTexture(sonic, "sonic.png", 0);
	glutDisplayFunc(Draw);
	engine.loop();
}

