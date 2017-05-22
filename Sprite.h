#pragma once
#include "stdafx.h"
#include <vector>
#include "Vec3.h"
#include <GL/glut.h>

class Sprite
{
	

public:
	int renderPriority;
	GLuint textureID;
	std::vector<Vec3> vectorOfVertex;
	std::vector<Vec3> vectorOfTextureCoordinates;
	Vec3 position;
	Vec3 velocity;
	float angle;
	float angleVariation;
	void Sprite::render();
	Sprite();
};

