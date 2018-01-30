#include "stdafx.h"
#include "Scene.h"
#include "SaltyEngineIncludes.h"


namespace salty
{
// ------------------------------------------------------------------------------------
Scene::Scene(const char* name, unsigned int id )
	: Named(name, id),
	  sceneActorRepository(),
	  povs()
{
}

// ------------------------------------------------------------------------------------
Scene::~Scene()
{
}

// ------------------------------------------------------------------------------------
const SceneActorVector& Scene::getSceneActors() const {
	return sceneActorRepository;
}

// ------------------------------------------------------------------------------------
const PovVector& Scene::getPovs() const {
	return povs;
}

// ------------------------------------------------------------------------------------
void Scene::addSceneActor(SceneActor* psceneActor) {
	sceneActorRepository.push_back(psceneActor);
}

// ------------------------------------------------------------------------------------
void Scene::removeSceneActor(unsigned int psceneActorID) {
	for (SceneActor* sceneActor : sceneActorRepository) {
		if (sceneActor->getSceneActorID() == psceneActorID) {
			SceneActorVector::iterator newEnd = std::remove(sceneActorRepository.begin(), sceneActorRepository.end(), sceneActor);
			sceneActorRepository.erase(newEnd, sceneActorRepository.end());
		}
	}
}

// ------------------------------------------------------------------------------------

POV* Scene::createStaticPov(float xPosition, float yPosition, unsigned int pPovID) {
	for (POV* pov : povs) {
		if (pov->getPovID() == pPovID) {
			std::cout << "A Pov with this ID already exists" << std::endl;
			return pov;
		}
	}

	POV* pPov = new POV(xPosition, yPosition, pPovID);
	povs.push_back(pPov);
	return pPov;
}

// ------------------------------------------------------------------------------------

POV* Scene::createPov(const Vec3& position, const Vec3& velocity, unsigned int pPovID) {
	for (POV* pov : povs) {
		if (pov->getPovID() == pPovID) {
			std::cout << "A Pov with this ID already exists" << std::endl;
			return nullptr;
		}
		else {
			POV* pPov = new POV(position, velocity, pPovID);
			return pPov;
		}
	}
	return nullptr;
}

// ------------------------------------------------------------------------------------

void Scene::removePOV(unsigned int pPovID) {
	for (POV* pov : povs) {
		if (pov->getPovID() == pPovID) {
			PovVector::iterator newEnd = std::remove(povs.begin(), povs.end(), pov);
			povs.erase(newEnd, povs.end());
		}
	}
}

// ------------------------------------------------------------------------------------

void Scene::render() {
	for (SceneActor* sceneActor : sceneActorRepository) {
		glLoadIdentity();

		if (sceneActor->getSprite()->isTransparent()) {
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		glTranslatef(sceneActor->getPosition().x, sceneActor->getPosition().y, 0);

		glBindTexture(GL_TEXTURE_2D, sceneActor->getSprite()->getTextureID());

		glEnable(GL_TEXTURE_2D);

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				glVertexPointer(3, GL_FLOAT, 0, &sceneActor->getVectorOfVertex()[0].x);
				glTexCoordPointer(3, GL_FLOAT, 0, &sceneActor->getVectorOfTextureCoordinates()[0].x);
				glDrawArrays(GL_QUADS, 0, sceneActor->getVectorOfVertex().size());
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);

		glDisable(GL_TEXTURE_2D);
	}
}

}
