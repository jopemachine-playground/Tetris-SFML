#pragma once

#include "UnitBlock.h"
#include "GamePool.h"

class BlockStack
{
	friend MovingBlock;

private:

	// 정적인 위치를 나타내는 UnitBlock 배열
	UnitBlock mBlock[COLUMN_PIXEL_NUMBER][ROW_PIXEL_NUMBER];

	BlockStack();

	static BlockStack* mInstance;

	// MovingBlock이 접근 가능한 메서드
	const void OneBlockSetSprite(int row, int column, sf::Sprite sprite) { mBlock[column][row].SetSprite(sprite); }

	const bool BlockIsMarked(int row, int column) { return mBlock[column][row].IsMarked(); }

	const void OneBlockMark(int row, int column) { mBlock[column][row].BlockMark(); }


public:

	~BlockStack() 
	{
		mInstance = nullptr;
	}

	static BlockStack* GetInstance() 
	{
		if (mInstance == nullptr) {
			mInstance = new BlockStack();
		}
		return mInstance;
	}

	/*
	블록 한 행이 모두 찬 경우 True 반환하고 점수 100점 올림.
	두 행이 가득차면 'Nice',
	세 행 이상 가득차면 'Excellent' 출력할 것.
	*/
	const bool CheckRowFulled();

	/*
	현재까지 쌓인 블록들을 모두 draw함.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	const bool IsGameEnd();

	void DEBUG_CheckAllBlock();

};
