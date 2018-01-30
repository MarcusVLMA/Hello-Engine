#pragma once

#include "stdafx.h"
#include "Camera.h"
#include "SceneActor.h"
#include "Sprite.h"

namespace salty
{
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


		// ---------------------------------- Scene Methods -----------------------------------

		Scene* createScene( const char* name, unsigned int id );
		Scene* getSceneByName( const char* name );
		Scene* getSceneById( unsigned int id );


		// ---------------------------------- SceneActor Methods ----------------------------------

		SceneActor* createSceneActor(Vec3Vector pvectorOfVertex, Vec3Vector pvectorOfTextureCoordinates, Sprite* psprite,
			float pxSpeed, float pySpeed,
			int prenderPriority, unsigned int psceneActorID);


		// ---------------------------------- Sprite Methods ----------------------------------

		Sprite* createSprite(const char *filename, bool isTransparent);


		// ---------------------------------- Camera Methods ----------------------------------
		Camera* createCamera(Scene* pscene, POV* ppov, float xPosition, float yPosition, float zPosition, unsigned int pcameraID);

		Camera* getCamera(unsigned int cameraID);

		void addCamera(Camera* pcamera);

		void removeCamera(unsigned int pcameraID);
	};
}
