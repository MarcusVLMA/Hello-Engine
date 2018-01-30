// SaltyEngine.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "SaltyEngineIncludes.h"

int main(int argc, char **argv)
{
	salty::Vec3Vector vertexVector(4);

	salty::Vec3 p1; p1.x = 0.0f; p1.y = 0.0f;

	salty::Vec3 p2; p2.x = 0.0325f; p2.y = 0.0f;

	salty::Vec3 p3; p3.x = 0.0325f; p3.y = 0.125f;

	salty::Vec3 p4; p4.x = 0.0f; p4.y = 0.125f;

	vertexVector.push_back(p1);
	vertexVector.push_back(p2);
	vertexVector.push_back(p3);
	vertexVector.push_back(p4);

	salty::Vec3Vector ballVector(4);

	salty::Vec3 b1; b1.x = 0.0f; b1.y = 0.0f;
	salty::Vec3 b2; b2.x = 0.0325f; b2.y = 0.0f;
	salty::Vec3 b3; b3.x = 0.0325f; b3.y = 0.0625f;
	salty::Vec3 b4; b4.x = 0.0f; b4.y = 0.0625f;

	ballVector.push_back(b1);
	ballVector.push_back(b2);
	ballVector.push_back(b3);
	ballVector.push_back(b4);

	salty::Vec3Vector textureVector(4);

	salty::Vec3 t1; t1.x = 0.0f; t1.y = 0.0f;

	salty::Vec3 t2; t2.x = 1.0f; t2.y = 0.0f;

	salty::Vec3 t3; t3.x = 1.0f; t3.y = 1.0f;

	salty::Vec3 t4; t4.x = 0.0f; t4.y = 1.0f;

	textureVector.push_back(t1);
	textureVector.push_back(t2);
	textureVector.push_back(t3);
	textureVector.push_back(t4);


	

	salty::SaltyEngine& engine = salty::SaltyEngine::getInstance();

	engine.start(argc, argv);
	engine.setWindow(0, 0, 1368, 768);
	engine.createWindow("Teste", false);

	salty::Scene* scene = engine.createScene("Cena 1", 1);

	salty::Sprite* barTexture = engine.createSprite("pongbar.png", false);

	salty::SceneActor* bar1 = engine.createSceneActor(vertexVector, textureVector, barTexture, 0, 0.0250f, 0, 1);
	salty::SceneActor* bar2 = engine.createSceneActor(vertexVector, textureVector, barTexture, 0, 0.0250f, 0, 2);
	salty::SceneActor* ball = engine.createSceneActor(ballVector, textureVector, barTexture, 0.125f, 0.125f, 0, 1);

	bar1->setPosition(-0.7f, 0.5f);
	bar2->setPosition(0.7f, 0.5f);

	scene->addSceneActor(bar1);
	scene->addSceneActor(bar2);
	scene->addSceneActor(ball);

	salty::POV* pov = scene->createStaticPov(0.0f, 0.0f, 1);

	salty::Camera* camera = engine.createCamera(scene, pov, 0, 0, 1, 1);

	engine.loop();

}

