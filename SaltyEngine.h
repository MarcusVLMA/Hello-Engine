#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Vec3.h"


/// TODO: buscar livros (b) Effective STL e (a) Effective C++
class SaltyEngine {
	//  usa ponteiro para Sprite, ou seja,  std::vector<Sprite*>
	std::vector<Sprite*> sprites;
	
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
	Sprite* createSprite( const char *fileName, int renderpriority);
	void render();
};
