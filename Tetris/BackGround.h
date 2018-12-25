#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SFML/Graphics.hpp"

#include "GamePool.h"

class BackGround {

private:

	sf::Texture mTexture;
	sf::Sprite mSprite;

public:

	BackGround();
	const sf::Sprite GetSprite() { return mSprite; }

};

#endif