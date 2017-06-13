#include "stdafx.h"
#include "SaltyEngineIncludes.h"

Sprite::Sprite()
	: vectorOfVertex(4), vectorOfTextureCoordinates(4),
	  position(), velocity(),
	  renderPriority(),
	  textureID(0),
	  angle(0),
	  angleSpeed(0.0f)
 {
	velocity.x = 0;
	velocity.y = 0;
}

Sprite::~Sprite()
{
}

// lhs = rhs
Sprite::Sprite( const Sprite& rhs )
	: vectorOfVertex(rhs.vectorOfVertex), vectorOfTextureCoordinates(rhs.vectorOfTextureCoordinates),
	  position(rhs.position), velocity(rhs.velocity),
	  renderPriority(rhs.renderPriority),
	  textureID(rhs.textureID),
	  angle(rhs.angle),
	  angleSpeed(rhs.angleSpeed)
{
}

Sprite& Sprite::operator=(const Sprite&)
{
return *this;
}

void Sprite::render() {
	glLoadIdentity();
	
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	

	glTranslatef(position.x, position.y, 0);

	glRotatef(angle, 0, 0, 1);

	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_TEXTURE_2D);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, &vectorOfVertex[0].x);
			glTexCoordPointer(3, GL_FLOAT, 0, &vectorOfTextureCoordinates[0].x);
			glDrawArrays(GL_QUADS, 0, vectorOfVertex.size());
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
}
