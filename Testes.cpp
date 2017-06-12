// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngineIncludes.h"

SaltyEngine engine;
Sprite *nave;
Sprite *background;
Camera *camera;

std::vector<Vec3> vertexOfBackground(4);

int main(int argc, char **argv)
{	
	vertexOfBackground[0].x = -1.0f;
	vertexOfBackground[0].y = -0.8f;

	vertexOfBackground[1].x = 1.0f;
	vertexOfBackground[1].y = -0.8f;

	vertexOfBackground[2].x = 1.0f;
	vertexOfBackground[2].y = 0.8f;

	vertexOfBackground[3].x = -1.0f;
	vertexOfBackground[3].y = 0.8f;

	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	nave = engine.createSprite("Naveira.png", 0, 0.0125, 0.0125);
	background = engine.createSprite("spacebackground.png", 1, 0, 0, vertexOfBackground);
	camera = engine.createCamera("Minha Camera", 0, 0, 0, nave);
	engine.setMainCharacter(nave);
	//engine.useCamera(camera); ?
	engine.loop();

	return 0;
}

