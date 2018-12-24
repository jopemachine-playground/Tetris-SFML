#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SFML/Graphics.hpp"

#include "Game.h"

class BackGround {

private:
	
	const size_t ONE_BLOCK_PIXEL = 39;
	const size_t ROW_PIXEL_NUMBER = 12;
	const size_t COLUMN_PIXEL_NUMBER = 22;
	const size_t ROW_PIXEL = ONE_BLOCK_PIXEL * ROW_PIXEL_NUMBER; // 468
	const size_t COLUMN_PIXEL = ONE_BLOCK_PIXEL * COLUMN_PIXEL_NUMBER; // 858

	const unsigned int BACKGROUND_POSITIONX = 50;
	const unsigned int BACKGROUND_POSITIONY = 30;

	sf::Texture mTexture;
	sf::Sprite mSprite;

public:

	BackGround();
	const sf::Sprite GetSprite() { return mSprite; }

};

#endif