#pragma once

#include <SFML/Graphics.hpp>

#include "UnitBlock.h"

class NextBlock
{

private:
		
	const static size_t MAX_UNITBLOCK_NUMBER = 4;

	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockShape mBlockShape;

	eBlockColor mMovingBlockColor;

	/*
	������ ����� ���, ������ �������� ������ �Լ�.
	*/
	const int getRandomShape();
	const int getRandomColor();


public:

	NextBlock();

	eBlockShape& GetBlockShape() { return mBlockShape; }

	eBlockColor& GetBlockColor() { return mMovingBlockColor; }

	void DrawNextBlock(sf::RenderWindow& window)
	{

		for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++)
		{
			window.draw(mMovingUnitBlock[i].GetSprite());
		}

	}

};