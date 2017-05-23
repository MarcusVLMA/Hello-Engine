#include "stdafx.h"
#include "SaltyEngine.h"

#include <GL/glut.h>
#ifdef WIN32
	#include <SOIL.h>
#else
	#include <SOIL/SOIL.h>
#endif

static SaltyEngine* theEngine = nullptr;

static void renderOneFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75, (1368 / 768), 0.5, 100);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

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
	theEngine = this;
}

SaltyEngine::~SaltyEngine()
{
	// liberar
	for( Sprite* ptr : sprites )
	{
		delete ptr;
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
	//Dúvida: Como passar os parâmetros da glutInitDisplayMode()
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
}

void SaltyEngine::createWindow(const char *header, bool isFullscreen) {
	glutCreateWindow(header);
	if (isFullscreen) {
		glutFullScreen();
	}
}

void SaltyEngine::loop() {
	glutDisplayFunc( renderOneFrame );
	

	glutMainLoop();
}

Sprite* SaltyEngine::createSprite( const char *fileName, int renderpriority) {
	Sprite *sprite = new Sprite();
	sprite->vectorOfTextureCoordinates[0].x = 0;
	sprite->vectorOfTextureCoordinates[0].y = 0;

	sprite->vectorOfTextureCoordinates[1].x = 1;
	sprite->vectorOfTextureCoordinates[1].y = 0;

	sprite->vectorOfTextureCoordinates[2].x = 1;
	sprite->vectorOfTextureCoordinates[2].y = 1;

	sprite->vectorOfTextureCoordinates[3].x = 0;
	sprite->vectorOfTextureCoordinates[3].y = 1;

	sprite->renderPriority = renderpriority;

	sprite->textureID = SOIL_load_OGL_texture(
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	//
	sprites.push_back( sprite );
	
	return sprite;
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

