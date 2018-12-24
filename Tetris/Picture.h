#pragma once

#include "SFML/Graphics.hpp"

#include "Game.h"

class Picture {

private:

	const unsigned int PICTURE_NUMBER = 10;

	sf::Texture mSelectedPictureTexture;
	sf::Sprite mSelectedPictureSprite;

public:

	Picture();

	const sf::Sprite GetSprite() { return mSelectedPictureSprite; }

};