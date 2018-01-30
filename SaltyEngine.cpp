#include "stdafx.h"
#include "SaltyEngineIncludes.h"

namespace salty
{
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(75, (1368 / 768), 0.5, 100);

		gluLookAt(salty::SaltyEngine::getInstance().getCamera(1)->getPosition().x,
				  salty::SaltyEngine::getInstance().getCamera(1)->getPosition().y, 1,
				  salty::SaltyEngine::getInstance().getCamera(1)->getPov()->getPosition().x,
				  salty::SaltyEngine::getInstance().getCamera(1)->getPov()->getPosition().y,
				  salty::SaltyEngine::getInstance().getCamera(1)->getPov()->getPosition().z,
				  0, 1, 0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		salty::SaltyEngine::getInstance().cameraRepository[0]->getScene()->render();

		glutSwapBuffers();
		glutPostRedisplay();
	}

	// ------------------------------------------------------------------------------------

	void SaltyEngine::keyboardFunc(unsigned char key, int x, int y) {
		
		if(key == 27) {
			salty::SaltyEngine::getInstance().kill();
		}
		if (key == 'd') {
			salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->setPositionX(
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getPosition().x +
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getSpeed().x
			);
		}
		if (key == 'a') {
			salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->setPositionX(
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getPosition().x -
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getSpeed().x
			);
		}
		if (key == 'w') {
			salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->setPositionY(
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getPosition().y +
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getSpeed().y
			);
		}
		if (key == 's') {
			salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->setPositionY(
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getPosition().y -
				salty::SaltyEngine::getInstance().sceneRepository[0]->getSceneActors()[0]->getSpeed().y
			);
		}
		
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
	Scene* SaltyEngine::createScene( const char* name, unsigned int id )
	{
		Scene* old = getSceneByName( name );
		if( old ) return old;

		old = getSceneById( id );
		if( old ) return old;

		old = new Scene( name, id );
		sceneRepository.push_back(old);
		return old;
	}
	Scene* SaltyEngine::getSceneByName( const char* name )
	{
		for( auto ptr : sceneRepository )
		{
			if( ptr->getName() == name )
				return ptr;
		}

		return nullptr;
	}
	Scene* SaltyEngine::getSceneById( unsigned int id )
	{
		for( auto ptr : sceneRepository )
		{
			if( ptr->getId() == id )
				return ptr;
		}

		return nullptr;
	}


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

	// #########################################################################################################################

	// ################################################### Camera Methods ###################################################

	Camera* SaltyEngine::createCamera(Scene* pscene, POV* ppov, float xPosition, float yPosition, float zPosition, unsigned int cameraID) {
		
		Camera* camera = new Camera(pscene, ppov, xPosition, yPosition, zPosition, cameraID);

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

	// #########################################################################################################################
}
