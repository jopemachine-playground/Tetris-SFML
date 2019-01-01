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
	UnitBlock�� ��ġ, Sprite���� ������ �� �ִ� Ŭ������
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

	void SetSprite(sf::Sprite sprite) { mSprite = sprite; }

	void SetMark(const bool marked) { mbMarked = marked; }

	void AddIndexX(const int indexX) { mPoint.IndexX += indexX; }

	void AddIndexY(const int indexY) { mPoint.IndexY += indexY; }

	void BlockMove(const int blockPixel_x, const int blockPixel_y) { mSprite.move(blockPixel_x, blockPixel_y); }

	void BlockMark() { mbMarked = true; }

	void BlockErase() { mbMarked = false; }

public:

	UnitBlock() {};

	sf::Sprite GetSprite() const { return mSprite; };

	sf::Vector2f GetPosition() const { return mSprite.getPosition(); }

	const unsigned int GetIndexX() const { return mPoint.IndexX; }

	const unsigned int GetIndexY() const { return mPoint.IndexY; }

	bool IsMarked() { return mbMarked; }


};

