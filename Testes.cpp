// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngineIncludes.h"

SaltyEngine engine;
Sprite *sonic;
Sprite *background;
Camera *camera;

std::vector<Vec3> vertexOfBackground(4);

int main(int argc, char **argv)
{	
	vertexOfBackground[0].x = -2.0f;
	vertexOfBackground[0].y = -1.0f;

	vertexOfBackground[1].x = 2.0f;
	vertexOfBackground[1].y = -1.0f;

	vertexOfBackground[2].x = 2.0f;
	vertexOfBackground[2].y = 1.0f;

	vertexOfBackground[3].x = -2.0f;
	vertexOfBackground[3].y = 1.0f;

	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	sonic = engine.createSprite("sonic.png", 0, 0.0125, 0.0125);
	background = engine.createSprite("background.png", 1, 0, 0, vertexOfBackground);
	camera = engine.createCamera("Minha Camera", 0, 0, 0, sonic);
	engine.setMainCharacter(sonic);
	//engine.useCamera(camera); ?
	engine.loop();

	return 0;
}

