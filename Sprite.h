#pragma once
#include "stdafx.h"
#include <vector>
#include "Vec3.h"
#include <GL/glut.h>

class Sprite
{
	

public:
	
	std::vector<Vec3> vectorOfVertex; // 24
	std::vector<Vec3> vectorOfTextureCoordinates; // 24
	Vec3 position; // 12
	Vec3 velocity; // 12	
	
	int renderPriority; // 4
	GLuint textureID; // 4
	
	float angle; // 4
	float angleVariation; // 4
	
	
	
	void render();
	Sprite();
	~Sprite();
	
	//
	Sprite( const Sprite& );
	Sprite& operator=(const Sprite&);
};

