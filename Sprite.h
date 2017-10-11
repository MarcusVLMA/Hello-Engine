#ifndef SALTY_ENGINE_SPRITE_CLASS_H__
#define SALTY_ENGINE_SPRITE_CLASS_H__
#pragma once

class Sprite {

	unsigned int textureID;
	bool transparent;

public:
	Sprite();
	Sprite(int ptextureID, bool ptransparent);
	~Sprite();

	Sprite(const Sprite&);
	Sprite& operator=(const Sprite&);

	unsigned int getTextureID() const;
	bool isTransparent() const;
};

#endif /* SALTY_ENGINE_SPRITE_CLASS_H__ */

