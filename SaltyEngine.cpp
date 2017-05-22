#include "stdafx.h"
#include "SaltyEngine.h"

void SaltyEngine::start(int argc, char **argv) {
	glutInit(&argc, argv);
}

void SaltyEngine::shutdown() {
	exit(0);
}

void SaltyEngine::setWindow(int positionX, int positionY, int width, int height) {
	glutInitWindowPosition(positionX, positionY);
	glutInitWindowSize(width, height);
	//Dúvida: Como passar os parâmetros da glutInitDisplayMode()
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
}

void SaltyEngine::createWindow(char *header, bool isFullscreen) {
	glutCreateWindow(header);
	if (isFullscreen) {
		glutFullScreen();
	}
}

void SaltyEngine::loop() {

	glutMainLoop();
}

void SaltyEngine::setTexture(Sprite *sprite, char *fileName, int renderpriority) {
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
}

int SaltyEngine::getLastLayer() {
	int lastLayer = 0;
	for (int i = 0; i < listToRender.size(); i++) {
		if (lastLayer < listToRender[i].renderPriority) {
			lastLayer = listToRender[i].renderPriority;
		}
	}
	return lastLayer;
}

void SaltyEngine::render() {
	for(int i = getLastLayer(); i >= 0; i--) {
		for (int j = 0; j < listToRender.size(); j++) {
			if (listToRender[j].renderPriority == i) {
				listToRender[j].render();
			}
		}
	}
}

void SaltyEngine::add(Sprite sprite) {
	listToRender.push_back(sprite);
}