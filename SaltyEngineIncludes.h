#ifndef SALTY_ENGINE_CORE_HEADERS_H__
#define SALTY_ENGINE_CORE_HEADERS_H__


// bibliotecas de containeres e algoritmos da STL
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>

#ifdef WIN32
#include <GL/glut.h>
#include <SOIL.h>
#else
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#endif

// pré-declarações de classes
class Camera;
class Scene;
class SceneActor;
class SaltyEngine;
class Sprite;
class POV;
class Vec3;

// containeres
typedef std::vector<Camera*>     CameraVector;
typedef std::vector<Scene*>		 SceneVector;
typedef std::vector<SceneActor*> SceneActorVector;
typedef std::vector<Sprite*>     SpriteVector;
typedef std::vector<POV*>		 PovVector;
#include "Vec3.h"
#include "POV.h"
#include "Sprite.h"
#include "SceneActor.h"
#include "Scene.h"
#include "Camera.h"

#include "SaltyEngine.h"

#endif /* SALTY_ENGINE_CORE_HEADERS_H__ */


