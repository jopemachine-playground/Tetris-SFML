#pragma once

#include "SFML/Graphics.hpp"

#include "GamePool.h"

class Picture {

private:

	const unsigned int PICTURE_NUMBER = 9;

	sf::Texture mSelectedPictureTexture;
	sf::Sprite mSelectedPictureSprite;
	unsigned int mSelectedNumber;

public:

	Picture();

	const sf::Sprite GetSprite() { return mSelectedPictureSprite; }

	const unsigned int GetSelectedNumber() { return mSelectedNumber; }

};