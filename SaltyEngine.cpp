#include "stdafx.h"
#include "SaltyEngineIncludes.h"

SaltyEngine* SaltyEngine::instance = nullptr;

// ------------------------------------------------------------------------------------

SaltyEngine::SaltyEngine()
	: sceneRepository(),
	  cameraRepository()
{}

// ------------------------------------------------------------------------------------

SaltyEngine::~SaltyEngine() {
	if (instance == this) {
		instance = nullptr;
	}

	for (Scene* scene : sceneRepository) {
		delete scene;
	}

	for (Camera* camera : cameraRepository) {
		delete camera;
	}

	//
	sceneRepository.clear();
	cameraRepository.clear();
}

// ------------------------------------------------------------------------------------

SaltyEngine& SaltyEngine::getInstance() {
	if (instance == nullptr) {
		instance = new SaltyEngine();
		return *instance;
	}
	else {
		return *instance;
	}
}

// ------------------------------------------------------------------------------------

void SaltyEngine::displayFunc() {

}

// ------------------------------------------------------------------------------------

void SaltyEngine::keyboardFunc(unsigned char key, int x, int y) {

}

// ------------------------------------------------------------------------------------

void SaltyEngine::mouseFunc(int button, int state, int x, int y) {

}

// ################################################### Engine Methods ###################################################

void SaltyEngine::start(int argc, char **argv) {
	glutInit(&argc, argv);
}

// ------------------------------------------------------------------------------------

void SaltyEngine::shutdown() {

}

// ------------------------------------------------------------------------------------

void SaltyEngine::kill() {
	exit(0);
}

// ------------------------------------------------------------------------------------

void SaltyEngine::setWindow(int positionX, int positionY, int width, int height) {
	glutInitWindowPosition(positionX, positionY);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
}

// ------------------------------------------------------------------------------------

void SaltyEngine::createWindow(const char *header, bool isFullscreen) {
	glutCreateWindow(header);
	if (isFullscreen) {
		glutFullScreen();
	}
}

// ------------------------------------------------------------------------------------

void SaltyEngine::loop() {
	glutMouseFunc(mouseFunc);
	glutKeyboardFunc(keyboardFunc);
	glutDisplayFunc(displayFunc);

	glutMainLoop();
}

// ------------------------------------------------------------------------------------


void SaltyEngine::screenshot() {
	int image;
	image = SOIL_save_screenshot("screenshot.png", SOIL_SAVE_TYPE_BMP, 0, 0, 1368, 768);
}

// #########################################################################################################################

// ################################################### SceneActor Methods ###################################################

SceneActor* SaltyEngine::createSceneActor(Vec3Vector pvectorOfVertex, Vec3Vector pvectorOfTextureCoordinates, Sprite* psprite,
	float pxSpeed, float pySpeed,
	int prenderPriority, unsigned int psceneActorID) {

	SceneActor* sceneActor = new SceneActor(pvectorOfVertex, pvectorOfTextureCoordinates, psprite,
		0, 0, // position
		pxSpeed, pySpeed, prenderPriority, psceneActorID);

	return sceneActor;
}

// ------------------------------------------------------------------------------------

// #########################################################################################################################

// ################################################### Sprite Methods ###################################################

Sprite* SaltyEngine::createSprite(const char *filename, bool isTransparent) {
	unsigned int textureID;

	textureID = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	Sprite* sprite = new Sprite(textureID, isTransparent);

	return sprite;
}
// ------------------------------------------------------------------------------------
/*Sprite* SaltyEngine::getSprite(unsigned int ptextureID) {
	for (Sprite* sprite : spriteRepository) {
		if (sprite->getTextureID() == ptextureID) {
			return sprite;
		}
	}

	return nullptr;
}
// ------------------------------------------------------------------------------------
void SaltyEngine::addSprite(Sprite* psprite) {
	spriteRepository.push_back(psprite);
}
// ------------------------------------------------------------------------------------
void SaltyEngine::removeSprite(unsigned int ptextureID) {
	for (Sprite* sprite : spriteRepository) {
		if (sprite->getTextureID == ptextureID) {
			SpriteVector::iterator newEnd = std::remove(spriteRepository.begin(), spriteRepository.end(), sprite);
			spriteRepository.erase(newEnd, spriteRepository.end());
		}
	}
}*/

// #########################################################################################################################

// ################################################### Camera Methods ###################################################

Camera* SaltyEngine::createCamera(float xLookingTo, float yLookingTo, float zLookingTo,
	float xPosition, float yPosition, float zPosition,
	unsigned int pcameraID) {

	Camera* camera = new Camera(xLookingTo, yLookingTo, zLookingTo, xPosition, yPosition, zPosition, pcameraID);

	cameraRepository.push_back(camera);

	return camera;
}
// ------------------------------------------------------------------------------------
Camera* SaltyEngine::getCamera(unsigned int cameraID) {
	for (Camera* camera : cameraRepository) {
		if (camera->getCameraID() == cameraID) {
			return camera;
		}
	}

	return nullptr;
}
// ------------------------------------------------------------------------------------
void SaltyEngine::addCamera(Camera* pcamera) {
	cameraRepository.push_back(pcamera);
}
// ------------------------------------------------------------------------------------
void SaltyEngine::removeCamera(unsigned int pcameraID) {
	for (Camera* camera : cameraRepository) {
		if (camera->getCameraID() == pcameraID) {
			CameraVector::iterator newEnd = std::remove(cameraRepository.begin(), cameraRepository.end(), camera);
			cameraRepository.erase(newEnd, cameraRepository.end());
		}
	}
}
// ------------------------------------------------------------------------------------
/*void SaltyEngine::followSceneActor(SceneActor* psceneActor, Camera* pcamera)
{
	pcamera->setLookingTo(psceneActor->getVectorOfVertex()[0]);
}*/
// #########################################################################################################################

