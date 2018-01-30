#include "stdafx.h"
#include "SaltyEngineIncludes.h"

namespace salty
{
	// ------------------------------------------------------------------------------------------------
	SceneActor::SceneActor()
		: vectorOfVertex(), vectorOfTextureCoordinates(),
		sprite(nullptr),
		position(0, 0),
		speed(0, 0),
		renderPriority(0) //Sem inicializar o gameActorID
	{
		sprite = new Sprite();
	}
	// ------------------------------------------------------------------------------------------------
	SceneActor::SceneActor(const Vec3Vector& pvectorOfVertex, const Vec3Vector& pvectorOfTextureCoordinates,
		Sprite* psprite,
		float pxPosition, float pyPosition,
		float pxSpeed, float pySpeed,
		int prenderPriority, unsigned int pgameActorID)
		: vectorOfVertex(pvectorOfVertex), vectorOfTextureCoordinates(pvectorOfTextureCoordinates),
		sprite(psprite),
		position(pxPosition, pyPosition),
		speed(pxSpeed, pySpeed),
		renderPriority(prenderPriority), sceneActorID(pgameActorID)
	{}
	// ------------------------------------------------------------------------------------------------
	SceneActor::~SceneActor()
	{
		sprite = nullptr;

		vectorOfVertex.clear();
		sceneActorID = 0;
	}
	// ------------------------------------------------------------------------------------------------
	SceneActor::SceneActor(const SceneActor& rhs)
		: vectorOfVertex(rhs.vectorOfVertex),
		sprite(rhs.sprite),
		sceneActorID(rhs.sceneActorID),
		position(rhs.position),
		speed(rhs.speed),
		renderPriority(rhs.renderPriority)
	{}
	// ------------------------------------------------------------------------------------------------
	SceneActor& SceneActor::operator=(const SceneActor& rhs) {
		// copiar
		if (this != &rhs)
		{
			vectorOfVertex = rhs.vectorOfVertex;
			sprite = rhs.sprite;
			sceneActorID = rhs.sceneActorID;
			position = rhs.position;
			speed = rhs.speed;
			renderPriority = rhs.renderPriority;
		}
		return *this;
	}
	// ------------------------------------------------------------------------------------------------
	const Vec3Vector& SceneActor::getVectorOfVertex() const {
		return vectorOfVertex;
	}
	// ------------------------------------------------------------------------------------------------
	const Vec3Vector& SceneActor::getVectorOfTextureCoordinates() const {
		return vectorOfTextureCoordinates;
	}
	// ------------------------------------------------------------------------------------------------
	Sprite* SceneActor::getSprite() const {
		return sprite;
	}
	// ------------------------------------------------------------------------------------------------
	Vec3 SceneActor::getSpeed() const {
		return speed;
	}
	// ------------------------------------------------------------------------------------------------
	Vec3 SceneActor::getPosition() const {
		return position;
	}
	// ------------------------------------------------------------------------------------------------
	int SceneActor::getRenderPriority() const {
		return renderPriority;
	}
	// ------------------------------------------------------------------------------------------------
	unsigned SceneActor::getSceneActorID() const {
		return sceneActorID;
	}
	// ------------------------------------------------------------------------------------------------
	void SceneActor::setPositionX(float xValue) {
		position.x = xValue;
	}
	// ------------------------------------------------------------------------------------------------
	void SceneActor::setPositionY(float yValue) {
		position.y = yValue;
	}
	// ------------------------------------------------------------------------------------------------
	void SceneActor::setPosition(float xValue, float yValue) {
		position.x = xValue;
		position.y = yValue;
	}
}
