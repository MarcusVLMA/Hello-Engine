#include "stdafx.h"
#include "SaltyEngineIncludes.h"

static SaltyEngine* theEngine = nullptr;

static void moveFromKeyboard(unsigned char key, int x, int y) {
	if (key == 27) {
		theEngine->shutdown();
	}
	if (key == 'd' || key == 'D') {
		theEngine->principalCharacter->position.x = theEngine->principalCharacter->position.x + theEngine->principalCharacter->velocity.x;
	}
	if (key == 'a' || key == 'A') {
		theEngine->principalCharacter->position.x = theEngine->principalCharacter->position.x - theEngine->principalCharacter->velocity.x;
	}
	if (key == 'w' || key == 'W') {
		theEngine->principalCharacter->position.y = theEngine->principalCharacter->position.y + theEngine->principalCharacter->velocity.y;
	}
	if (key == 's' || key == 'S') {
		theEngine->principalCharacter->position.y = theEngine->principalCharacter->position.y - theEngine->principalCharacter->velocity.y;
	}
	if (key == 'q' || key == 'Q') {
		theEngine->principalCharacter->angle = theEngine->principalCharacter->angle + theEngine->principalCharacter->angleSpeed;
	}
	if (key == 'e' || key == 'E') {
		theEngine->principalCharacter->angle = theEngine->principalCharacter->angle - theEngine->principalCharacter->angleSpeed;
	}
}

static void renderFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75, (1366 / 768), 0.5, 100);
	gluLookAt(0, 0, 1, theEngine->activeCamera->lookingTo.x, theEngine->activeCamera->lookingTo.y, theEngine->activeCamera->lookingTo.z, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	if( theEngine != nullptr )
	{
		theEngine->render();
	}

	glutSwapBuffers();
	glutPostRedisplay();
}

SaltyEngine::SaltyEngine()
	: sprites()
{
	StandardVectorOfVertex[0].x = 0.0f;
	StandardVectorOfVertex[0].y = 0.0f;
	StandardVectorOfVertex[1].x = 0.125f;
	StandardVectorOfVertex[1].y = 0.0f;
	StandardVectorOfVertex[2].x = 0.125f;
	StandardVectorOfVertex[2].y = 0.125f;
	StandardVectorOfVertex[3].x = 0.0f;
	StandardVectorOfVertex[3].y = 0.125f;

	theEngine = this;
}

SaltyEngine::~SaltyEngine()
{
	// liberar
	for( Sprite* sprite : sprites )
	{
		delete sprite;
	}
	sprites.clear();
}

void SaltyEngine::start(int argc, char **argv) {
	// TODO buscar algum argumento de linha de comando para usar depois

	glutInit(&argc, argv);
}

void SaltyEngine::shutdown() {
	exit(0);
}

void SaltyEngine::setWindow(int positionX, int positionY, int width, int height) {
	glutInitWindowPosition(positionX, positionY);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
}

void SaltyEngine::createWindow(const char *header, bool isFullscreen) {
	glutCreateWindow(header);
	if (isFullscreen) {
		glutFullScreen();
	}
}

void SaltyEngine::loop() {
	glutKeyboardFunc(moveFromKeyboard);
	glutDisplayFunc(renderFrame);
	glutMainLoop();
}

Sprite* SaltyEngine::createSprite(const char *fileName, int renderpriority, std::vector<Vec3> ownVectorOfVertex = theEngine->StandardVectorOfVertex) {
	Sprite *sprite = new Sprite();
	sprite->vectorOfTextureCoordinates[0].x = ownVectorOfVertex[0].x;
	sprite->vectorOfTextureCoordinates[0].y = ownVectorOfVertex[0].y;

	sprite->vectorOfTextureCoordinates[1].x = ownVectorOfVertex[1].x;
	sprite->vectorOfTextureCoordinates[1].y = ownVectorOfVertex[1].y;

	sprite->vectorOfTextureCoordinates[2].x = ownVectorOfVertex[2].x;
	sprite->vectorOfTextureCoordinates[2].y = ownVectorOfVertex[2].y;

	sprite->vectorOfTextureCoordinates[3].x = ownVectorOfVertex[3].x;
	sprite->vectorOfTextureCoordinates[3].y = ownVectorOfVertex[3].y;

	sprite->renderPriority = renderpriority;

	sprite->textureID = SOIL_load_OGL_texture(
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	//
	sprites.push_back(sprite);
	
	return sprite;
}

Camera* SaltyEngine::createCamera(char *name, float lookX, float lookY, float lookZ, Sprite *sprite = nullptr) {
	Camera *camera = new Camera();
	camera->cameraName = name;

	if(sprite != nullptr) {
		camera->lookingTo.x = sprite->vectorOfVertex[0].x;
		camera->lookingTo.y = sprite->vectorOfVertex[0].y;
		camera->lookingTo.z = sprite->vectorOfVertex[0].z;

		cameras.push_back(camera);

		return camera;

	} else {
		camera->lookingTo.x = lookX;
		camera->lookingTo.y = lookY;
		camera->lookingTo.z = lookZ;

		cameras.push_back(camera);

		return camera;
	}
}

void SaltyEngine::useCamera(Camera *camera) {
	theEngine->activeCamera = camera;
}

int SaltyEngine::getLastLayer() {
	int lastLayer = 0;
	for (int i = 0; i < sprites.size(); i++) {
		if (lastLayer < sprites[i]->renderPriority) {
			lastLayer = sprites[i]->renderPriority;
		}
	}
	return lastLayer;
}

void SaltyEngine::render() {
	for(int i = getLastLayer(); i >= 0; i--) {
		for (int j = 0; j < sprites.size(); j++) {
			if (sprites[j]->renderPriority == i) {
				sprites[j]->render();
			}
		}
	}
}

void SaltyEngine::principalCharacter(Sprite *character) {
	theEngine->principalCharacter = character;
}