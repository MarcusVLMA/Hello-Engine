#pragma once
#include "stdafx.h"
#include <GL/glut.h>
#include "Sprite.h"
#include "Vec3.h"
#ifdef WIN32
	#include <SOIL.h>
#else
	#include <SOIL/SOIL.h>
#endif

class SaltyEngine {
	std::vector<Sprite> listToRender;
	int SaltyEngine::getLastLayer();
public:
	void SaltyEngine::start(int argc, char **argv);
	void SaltyEngine::shutdown();
	void SaltyEngine::setWindow(int positionX, int positionY, int width, int height);
	void SaltyEngine::createWindow(char *header, bool isFullscreen);
	void SaltyEngine::loop(/* void(*drawingFunction)(void)*/);
	void SaltyEngine::setTexture(Sprite *sprite, char *fileName, int renderpriority);
	void SaltyEngine::render();
	void SaltyEngine::add(Sprite sprite);
};
