#pragma once
#include "SaltyEngineIncludes.h"

namespace salty
{
	class Scene : public Named {
		friend class SaltyEngine;

		SceneActorVector sceneActorRepository;				//Vector with all SceneActors presents on the scene.
		PovVector povs;										//Vector with all POVS presents on the scene. (POV = Point Of View)

		Scene( const char* name, unsigned int id );
	public:

		Scene(const Scene&) = delete;
		Scene& operator=(const Scene&) = delete;
		~Scene();

		const SceneActorVector& getSceneActors() const;     //Return the sceneActorRepository.
		const PovVector&        getPovs()        const;     //Return the POVS vector.

		void addSceneActor    (SceneActor*  psceneActor  );    //Add a Scene Actor to the Scene.
		void removeSceneActor (unsigned int psceneActorID); //Remove a Scene Actor from the Scene by giving the Scene Actor's ID.

		POV* createStaticPov (float xPosition, float yPosition, unsigned int pPovID); //Creates a POV which don't move.
		POV* createPov       (const Vec3& Position , const Vec3& Velocity , unsigned int pPovID); //Creates a POV which move.
	
		void removePOV(unsigned int pPovID);				//Remove a POV by giving it povID.

		void render();										//Render the scene.
	};
}
