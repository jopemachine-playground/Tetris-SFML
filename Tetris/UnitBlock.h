#pragma once

#ifndef UNITBLOCK_H
#define UNITBLOCK_H

#include "SFML/Graphics.hpp"
#include "GamePool.h"

class UnitBlock {

private:
	
	//sf::Vector2f mPosition;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	eBlockColor mColor;

	bool mMarked = false;

public:

	UnitBlock();

	//void SetPosition(int x, int y) { mPosition.x = x; mPosition.y = y; }

	//sf::Vector2f GetPosition() { return mPosition; }

	sf::Sprite GetSprite() { return mSprite; };

	void SetSprite(sf::Sprite sprite) { mSprite = sprite; }

	void SetPosition(int x, int y) { mSprite.setPosition(x, y); }

	void BlockMove(int x, int y) { mSprite.move(x,y); }

	bool IsMarked() { return mMarked; }

	void BlockMark() { mMarked = true; }

	void BlockErase() { mMarked = false; }

};

#endif