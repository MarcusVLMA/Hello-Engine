#include "stdafx.h"
#include "SaltyEngineIncludes.h"

namespace salty
{
	Sprite::Sprite()
		: textureID(0),
		transparent(false)
	{}

	Sprite::Sprite(int ptextureID, bool ptransparent)
		: textureID(ptextureID),
		transparent(ptransparent)
	{}

	Sprite::~Sprite()
	{
		textureID = 0;
		transparent = false;
	}

	Sprite::Sprite(const Sprite& rhs)
		: textureID(rhs.textureID),
		transparent(rhs.transparent)
	{}

	Sprite& Sprite::operator=(const Sprite&) {
		return *this;
	}

	unsigned int Sprite::getTextureID() const {
		return textureID;
	}

	bool Sprite::isTransparent() const {
		return transparent;
	}
}
