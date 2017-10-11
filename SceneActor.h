#ifndef SALTY_ENGINE_SCENE_ACTOR_CLASS_H__
#define SALTY_ENGINE_SCENE_ACTOR_CLASS_H__

#include "Vec3.h"

class SceneActor {
	Vec3Vector vectorOfVertex;
	Vec3Vector vectorOfTextureCoordinates;

	Sprite* sprite;

	Vec3 position;
	Vec3 speed;

	int renderPriority;
	unsigned int sceneActorID;

public:
	SceneActor();

	SceneActor(
		const Vec3Vector& pvectorOfVertex, const Vec3Vector& pvectorOfTextureCoordinates,
		Sprite* psprite,
		float pxPosition, float pyPosition,
		float pxSpeed, float pySpeed,
		int prenderPriority, unsigned int pgameActorID);

	~SceneActor();

	SceneActor(const SceneActor&);
	SceneActor& operator=(const SceneActor&);

	const Vec3Vector& getVectorOfVertex()             const;
	const Vec3Vector& getVectorOfTextureCoordinates() const;

	Sprite* getSprite()   const;
	Vec3    getPosition() const;
	Vec3    getSpeed()    const;

	int          getRenderPriority() const;
	unsigned int getSceneActorID()   const;
};

#endif /* SALTY_ENGINE_SCENE_ACTOR_CLASS_H__ */

