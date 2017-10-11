#pragma once
#include "SaltyEngineIncludes.h"

class Scene {
	SceneActorVector sceneActorRepository;				//Vector with all SceneActors presents on the scene.
	PovVector povs;										//Vector with all POVS presents on the scene. (POV = Point Of View)

public:
	Scene();
	~Scene();

	const SceneActorVector& getSceneActors() const;     //Return the sceneActorRepository.
	const PovVector&        getPovs()        const;     //Return the POVS vector.

	void addSceneActor    (SceneActor*  psceneActor  );    //Add a Scene Actor to the Scene.
	void removeSceneActor (unsigned int psceneActorID); //Remove a Scene Actor from the Scene by giving the Scene Actor's ID.

	POV* createStaticPov (float xPosition, float yPosition, unsigned int pPovID); //Creates a POV which don't move.
	POV* createPov       (Vec3 *Position , Vec3 *Velocity , unsigned int pPovID); //Creates a POV which move.

	void removePOV(unsigned int pPovID);				//Remove a POV by giving it povID.
	
	void render();										//Render the scene.
};

