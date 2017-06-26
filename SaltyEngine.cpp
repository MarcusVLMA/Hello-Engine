#include "stdafx.h"
#include "SaltyEngineIncludes.h"

static SaltyEngine* theEngine = nullptr;

std::vector<Vec3> SaltyEngine::StandardVectorOfVertex;
std::vector<Vec3> SaltyEngine::vectorOfVerticalGrid;
std::vector<Vec3> SaltyEngine::vectorOfHorizontalGrid;


void SaltyEngine::moveFromKeyboard(unsigned char key, int x, int y) {

	assert(theEngine);

	if (key == 27 ) {
		theEngine->shutdown();
	}

	if (!theEngine->debugMode) {
		assert(theEngine->principalCharacter);
		
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
		if (key == 'b' || key == 'B') {
			theEngine->debugMode = true;
		}
		if (theEngine->activeCamera) {
			theEngine->activeCamera->lookingTo = theEngine->principalCharacter->position;
		}
	}
	else {
		assert(theEngine->activeCamera);

		if (key == 'd' || key == 'D') {
			theEngine->activeCamera->position.x = theEngine->activeCamera->position.x + 0.125f;
		}
		if (key == 'a' || key == 'A') {
			theEngine->activeCamera->position.x = theEngine->activeCamera->position.x - 0.125f;
		}
		if (key == 'w' || key == 'W') {
			theEngine->activeCamera->position.y = theEngine->activeCamera->position.y + 0.125f;
		}
		if (key == 's' || key == 'S') {
			theEngine->activeCamera->position.y = theEngine->activeCamera->position.y - 0.125f;
		}
		if (key == 'q' || key == 'Q') {
			theEngine->activeCamera->position.z = theEngine->activeCamera->position.z + 0.125f;
		}
		if (key == 'e' || key == 'E') {
			theEngine->activeCamera->position.z = theEngine->activeCamera->position.z - 0.125f;
		}
		if (key == 'b' || key == 'B') {
			theEngine->debugMode = false;
		}
		theEngine->activeCamera->lookingTo.x = theEngine->activeCamera->position.x;
		theEngine->activeCamera->lookingTo.y = theEngine->activeCamera->position.y;
		theEngine->activeCamera->lookingTo.z = theEngine->activeCamera->position.z - 1;
	}
	if (key == 'g' || key == 'G') {
		if (theEngine->turnGridOn) {
			theEngine->turnGridOn = false;
		}
		else {
			theEngine->turnGridOn = true;
		}
	}
	
	if (key == 'p' || key == 'P') {
		theEngine->screenshot();
	}
}

void SaltyEngine::renderFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75, (1368 / 768), 0.5, 100);
	
	if(theEngine->activeCamera)
	{
		if (!theEngine->debugMode) {
			gluLookAt(theEngine->principalCharacter->position.x, theEngine->principalCharacter->position.y, 1, theEngine->activeCamera->lookingTo.x, theEngine->activeCamera->lookingTo.y, theEngine->activeCamera->lookingTo.z, 0, 1, 0);
		}
		else {
			gluLookAt(theEngine->activeCamera->position.x, theEngine->activeCamera->position.y, theEngine->activeCamera->position.z, theEngine->activeCamera->lookingTo.x, theEngine->activeCamera->lookingTo.y, theEngine->activeCamera->lookingTo.z, 0, 1, 0);
		}
	} else {
		gluLookAt( /*eye*/ 0, 0, 1,  /*target*/ 0,0,0, /*up*/ 0, 1, 0);
	}

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
	StandardVectorOfVertex.resize(4);
	StandardVectorOfVertex[0].x = -0.125f;
	StandardVectorOfVertex[0].y = -0.203f;
	StandardVectorOfVertex[1].x = 0.125f;
	StandardVectorOfVertex[1].y = -0.203f;
	StandardVectorOfVertex[2].x = 0.125f;
	StandardVectorOfVertex[2].y = 0.203f;
	StandardVectorOfVertex[3].x = -0.125f;
	StandardVectorOfVertex[3].y = 0.203f;

	turnGridOn = false;

	debugMode = false;

	vectorOfVerticalGrid.resize(32);
	vectorOfHorizontalGrid.resize(26);

	vectorOfVerticalGrid[0].x = -1.0f;
	vectorOfVerticalGrid[0].y = -0.8f;

	for(int i = 1; i < 16; i++) {
		vectorOfVerticalGrid[i].x = vectorOfVerticalGrid[0].x + (0.125f*i);
		vectorOfVerticalGrid[i].y = -0.8f; 
	}
	for(int i = 31; i > 15; i--) {
		vectorOfVerticalGrid[i].x = vectorOfVerticalGrid[i-16].x;
		vectorOfVerticalGrid[i].y = 0.8f; 
	}

	vectorOfHorizontalGrid[0].x = -1.0f;
	vectorOfHorizontalGrid[0].y = -0.8f;
	
	for(int i = 1; i <= 13; i++) {
		vectorOfHorizontalGrid[i].x = -1.0f;
		vectorOfHorizontalGrid[i].y = vectorOfHorizontalGrid[0].y + (0.125f*i);
	}
	for(int i = 25; i > 12; i--) {
		vectorOfHorizontalGrid[i].x = 1.0f;
		vectorOfHorizontalGrid[i].y = vectorOfHorizontalGrid[i-13].y;
	}
	
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

Sprite* SaltyEngine::createSprite(const char *fileName, int renderpriority, float velocityX, float velocityY, bool isTransparent, std::vector<Vec3> ownVectorOfVertex ) {
	Sprite *sprite = new Sprite();

	sprite->vectorOfVertex[0].x = ownVectorOfVertex[0].x;
	sprite->vectorOfVertex[0].y = ownVectorOfVertex[0].y;

	sprite->vectorOfVertex[1].x = ownVectorOfVertex[1].x;
	sprite->vectorOfVertex[1].y = ownVectorOfVertex[1].y;

	sprite->vectorOfVertex[2].x = ownVectorOfVertex[2].x;
	sprite->vectorOfVertex[2].y = ownVectorOfVertex[2].y;

	sprite->vectorOfVertex[3].x = ownVectorOfVertex[3].x;
	sprite->vectorOfVertex[3].y = ownVectorOfVertex[3].y;


	sprite->vectorOfTextureCoordinates[0].x = 0.0f;
	sprite->vectorOfTextureCoordinates[0].y = 0.0f;

	sprite->vectorOfTextureCoordinates[1].x = 1.0f;
	sprite->vectorOfTextureCoordinates[1].y = 0.0f;

	sprite->vectorOfTextureCoordinates[2].x = 1.0f;
	sprite->vectorOfTextureCoordinates[2].y = 1.0f;

	sprite->vectorOfTextureCoordinates[3].x = 0.0f;
	sprite->vectorOfTextureCoordinates[3].y = 1.0f;

	sprite->renderPriority = renderpriority;

	sprite->velocity.x = velocityX;
	sprite->velocity.y = velocityY;

	sprite->textureID = SOIL_load_OGL_texture(
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	sprite->transparent = isTransparent;
	//
	sprites.push_back(sprite);
	
	return sprite;
}

Camera* SaltyEngine::createCamera(const char *name, float lookX, float lookY, float lookZ, Sprite *sprite ) {
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

void SaltyEngine::setMainCharacter(Sprite *character) {
	theEngine->principalCharacter = character;
}

void SaltyEngine::render() {
	for(int i = getLastLayer(); i >= 0; i--) {
		for (int j = 0; j < sprites.size(); j++) {
			if (sprites[j]->renderPriority == i) {
				sprites[j]->render();
			}
		}
	}
	if (theEngine->turnGridOn) {
		theEngine->renderGrid();
	}
}

void SaltyEngine::renderGrid() {
	glLoadIdentity();

	//glTranslatef(position.x, position.y, 0);

	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 16, &vectorOfVerticalGrid[0].x);
		glDrawArrays(GL_LINES, 0, vectorOfVerticalGrid.size());
	glDisableClientState(GL_VERTEX_ARRAY);

	//std::cout << "x0:" << vectorOfVerticalGrid[0].x << " " << "y0:" << vectorOfVerticalGrid[0].y << std::endl;
	//std::cout << "x16:" << vectorOfVerticalGrid[16].x << " " << "y16:" << vectorOfVerticalGrid[16].y << std::endl << std::endl;
	
	glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 13, &vectorOfHorizontalGrid[0].x);
		glDrawArrays(GL_LINES, 0, vectorOfHorizontalGrid.size());
	glDisableClientState(GL_VERTEX_ARRAY);

}

void SaltyEngine::screenshot() {
	int image;
	image = SOIL_save_screenshot("screenshot.png", SOIL_SAVE_TYPE_BMP, 0, 0, 1368, 768);
}

