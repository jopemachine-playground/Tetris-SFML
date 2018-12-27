#pragma once

#ifndef UNITBLOCK_H
#define UNITBLOCK_H

#include "SFML/Graphics.hpp"
#include "GamePool.h"

class UnitBlock {

private:
	
	struct Point {
		unsigned int IndexX;
		unsigned int IndexY;
	} mPoint;

	sf::Texture mTexture;
	sf::Sprite mSprite;
	eBlockColor mColor;

	bool mMarked = false;

public:

	UnitBlock();

	sf::Sprite GetSprite() { return mSprite; };

	sf::Vector2f GetPosition() { return mSprite.getPosition(); }
	
	const unsigned int GetIndexX() { return mPoint.IndexX; }

	const unsigned int GetIndexY() { return mPoint.IndexY; }

	void AddIndexX(int indexX) { mPoint.IndexX += indexX; }

	void AddIndexY(int indexY) { mPoint.IndexY += indexY; }

	void SetSprite(sf::Sprite sprite) { mSprite = sprite; }

	void SetPosition(int blockPixel_x, int blockPixel_y);

	bool IsMarked() { return mMarked; }

	void BlockMove(int blockPixel_x, int blockPixel_y) { mSprite.move(blockPixel_x, blockPixel_y); }

	void BlockMark() { mMarked = true; }

	void BlockErase() { mMarked = false; }

};

#endif