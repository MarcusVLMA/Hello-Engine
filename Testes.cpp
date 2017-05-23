// Testes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SaltyEngine.h"

#include <iostream>

SaltyEngine engine;
Sprite *sonic;

void Draw() {
	
}

int main(int argc, char **argv)
{

	std::cout << sizeof(Sprite) << std::endl;
	std::cout << sizeof(std::vector<Vec3>) << std::endl;

	engine.start(argc, argv);
	engine.setWindow(0, 0, 1366, 768);
	engine.createWindow("Made with SaltyEngine", false);
	
	sonic = new Sprite(); // NECESSÁRIO
	engine.setTexture(sonic, "sonic.png", 0);
	glutDisplayFunc(Draw);
	engine.loop();
	
	return 0;
}

