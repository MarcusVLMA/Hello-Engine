#pragma once
#include "stdafx.h"

// bibliotecas de containeres
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <iostream>

#include <GL/glut.h>
#ifdef WIN32
	#include <SOIL.h>
#else
	#include <SOIL/SOIL.h>
#endif

class Camera;
class SaltyEngine;
class Sprite;
class Vec3;


#include "Vec3.h"
#include "Sprite.h"
#include "SaltyEngine.h"
#include "Camera.h"


/*Lista de Mudanças
- Criação de um Vetor de Vértices padrão(SaltyEngine.h)
	*Alteração no Construtor
- Implementação de camera (Camera.h)
	*Alteração em SaltyEngine.cpp->renderOneFrame()
- Implementação de movimentação (SaltyEngine.h)
	*Obs: Sem parallax

*/

/*Duvidas
- Como funciona
	*Sprite( const Sprite& );
	*Sprite& operator=(const Sprite&);
*/
