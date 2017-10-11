#pragma once

#include "stdafx.h"
#include "Camera.h"
#include "SceneActor.h"
#include "Sprite.h"

class SaltyEngine {

	SaltyEngine();

	static SaltyEngine* instance;

	SceneVector sceneRepository;
	CameraVector cameraRepository;

	static void displayFunc();
	static void keyboardFunc(unsigned char key, int x, int y);
	static void mouseFunc(int button, int state, int x, int y);

public:

	static SaltyEngine& getInstance();

	~SaltyEngine();

	// ---------------------------------- Engine Methods ----------------------------------

	void start(int argc, char **argv);
	void shutdown();
	void kill();
	void setWindow(int positionX, int positionY, int width, int height);
	void createWindow(const char *header, bool isFullscreen);
	void loop();
	void screenshot();

	// -------------------------------------------------------------------------------------


	// ---------------------------------- SceneActor Methods ----------------------------------

	SceneActor* createSceneActor(Vec3Vector pvectorOfVertex, Vec3Vector pvectorOfTextureCoordinates, Sprite* psprite,
		float pxSpeed, float pySpeed,
		int prenderPriority, unsigned int psceneActorID);

	// ----------------------------------------------------------------------------------------


	// ---------------------------------- Sprite Methods ----------------------------------

	Sprite* createSprite(const char *filename, bool isTransparent);


	// ------------------------------------------------------------------------------------

	// ---------------------------------- Camera Methods ----------------------------------
	Camera* createCamera(float xLookingTo, float yLookingTo, float zLookingTo,
		float xPosition, float yPosition, float zPosition,
		unsigned int pcameraID);

	Camera* getCamera(unsigned int cameraID);

	void addCamera(Camera* pcamera);

	void removeCamera(unsigned int pcameraID);

	//void followSceneActor(SceneActor*, Camera*);
};

