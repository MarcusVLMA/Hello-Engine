#pragma once
#include "stdafx.h"
#include "SaltyEngineIncludes.h"


/// TODO: buscar livros (b) Effective STL e (a) Effective C++
class SaltyEngine {
	//  usa ponteiro para Sprite, ou seja,  std::vector<Sprite*>
	std::vector<Sprite*> sprites;
	std::vector<Camera*> cameras;
	static std::vector<Vec3> StandardVectorOfVertex;
	static std::vector<Vec3> vectorOfVerticalGrid;
	static std::vector<Vec3> vectorOfHorizontalGrid;
	Sprite *principalCharacter;
	bool turnGridOn;
	bool debugMode;

	int getLastLayer();
	
	static void moveFromKeyboard(unsigned char key, int x, int y);
	static void renderFrame();

public:
	
	Camera *activeCamera;

	SaltyEngine();
	~SaltyEngine();

	// F1: usando "=	delete", você marca o método como "não existe". Caso contrário, o C++ cria uma implementação padrão para você.
	SaltyEngine( const SaltyEngine& ) = delete;
	SaltyEngine& operator=( const SaltyEngine& ) = delete;

	void start(int argc, char **argv);
	void shutdown();
	void setWindow(int positionX, int positionY, int width, int height);
	void createWindow(const char *header, bool isFullscreen);
	void loop();
	Sprite* createSprite(const char *fileName, int renderpriority, float velocityX, float velocityY, bool isTransparent, std::vector<Vec3> ownVectorOfVertex = StandardVectorOfVertex);
	Camera* createCamera(const char *name, float lookX, float lookY, float lookZ, Sprite *sprite = nullptr);
	void useCamera(Camera *camera);
	void setMainCharacter(Sprite *character);
	void render();
	void renderGrid();
	void screenshot();
};
