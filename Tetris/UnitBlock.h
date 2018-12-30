#pragma once

#ifndef UNITBLOCK_H
#define UNITBLOCK_H

#include <SFML/Graphics.hpp>
#include "GamePool.h"

#include <iostream>

class UnitBlock {

private:
	
	struct Point {
		unsigned int IndexX;
		unsigned int IndexY;
	} mPoint;

	sf::Texture mTexture;
	sf::Sprite mSprite;
	eBlockColor mColor;

	bool mbMarked = false;

public:

	UnitBlock() {};

	sf::Sprite GetSprite() { return mSprite; };

	sf::Vector2f GetPosition() { return mSprite.getPosition(); }
	
	const unsigned int GetIndexX() const { return mPoint.IndexX; }

	const unsigned int GetIndexY() const { return mPoint.IndexY; }

	void AddIndexX(int indexX) { mPoint.IndexX += indexX; }

	void AddIndexY(int indexY) { mPoint.IndexY += indexY; }

	void SetSprite(sf::Sprite sprite) { mSprite = sprite; }

	void SetPosition(int blockPixel_x, int blockPixel_y);

	void SetPositionByIndex(int index_x, int index_y);

	bool IsMarked() { return mbMarked; }

	void SetMark(bool marked) { mbMarked = marked; }

	void BlockMove(int blockPixel_x, int blockPixel_y) { mSprite.move(blockPixel_x, blockPixel_y); }

	void BlockMark() { mbMarked = true; }

	void BlockErase() { mbMarked = false; }

};

#endif