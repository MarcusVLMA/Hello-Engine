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

/// TODO: buscar livros (b) Effective STL e (a) Effective C++
class SaltyEngine {
	// TODO usar ponteiro para Sprite, ou seja,  std::vector<Sprite*>
	std::vector<Sprite> sprites;
	int getLastLayer();
public:
	
	SaltyEngine();
	~SaltyEngine();

	// F1: usando "=	delete", você marca o método como "não existe". Caso contrário, o C++ cria uma implementação padrão para você.
	SaltyEngine( const SaltyEngine& ) = delete;
	SaltyEngine& operator=( const SaltyEngine& ) = delete;

	void start(int argc, char **argv);
	void shutdown();
	void setWindow(int positionX, int positionY, int width, int height);
	void createWindow(const char *header, bool isFullscreen);
	void loop(/* void(*drawingFunction)(void)*/);
	void setTexture(Sprite *sprite, const char *fileName, int renderpriority);
	void render();
	void add(Sprite sprite);
};
