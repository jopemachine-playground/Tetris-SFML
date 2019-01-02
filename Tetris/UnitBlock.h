#pragma once

#include <SFML/Graphics.hpp>
#include "GamePool.h"

#include <iostream>

class MovingBlock;
class NextBlock;
class BlockStack;

class UnitBlock 
{
	/*
	UnitBlock의 위치, Sprite까지 변경할 수 있는 클래스들
	*/
	friend MovingBlock;
	friend NextBlock;
	friend BlockStack;

private:
	
	struct Point
	{
		unsigned int IndexX;
		unsigned int IndexY;
	} mPoint;

	sf::Texture mTexture;
	sf::Sprite mSprite;
	eBlockColor mColor;

	bool mbMarked = false;

	void SetPosition(const int blockPixel_x, const int blockPixel_y);

	void SetPositionByIndex(const int index_x, const int index_y);

	inline void SetSprite(sf::Sprite sprite) { mSprite = sprite; }

	inline void SetMark(const bool marked) { mbMarked = marked; }

	inline void AddIndexX(const int indexX) { mPoint.IndexX += indexX; }

	inline void AddIndexY(const int indexY) { mPoint.IndexY += indexY; }

	void BlockMove(const int blockPixel_x, const int blockPixel_y) { mSprite.move(blockPixel_x, blockPixel_y); }

	inline void BlockMark() { mbMarked = true; }

	inline void BlockErase() { mbMarked = false; }

public:

	UnitBlock() {};

	inline sf::Sprite GetSprite() const { return mSprite; };

	inline sf::Vector2f GetPosition() const { return mSprite.getPosition(); }

	inline const unsigned int GetIndexX() const { return mPoint.IndexX; }

	inline const unsigned int GetIndexY() const { return mPoint.IndexY; }

	inline bool IsMarked() { return mbMarked; }


};

