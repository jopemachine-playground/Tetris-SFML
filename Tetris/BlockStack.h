#pragma once

#ifndef BLOCKSTACK_H
#define BLOCKSTACK_H

#include "UnitBlock.h"
#include "GamePool.h"

class BlockStack {

private:

	// 정적인 위치를 나타내는 UnitBlock 배열
	UnitBlock mBlock[COLUMN_PIXEL_NUMBER][ROW_PIXEL_NUMBER];

	BlockStack();

	static BlockStack* mInstance;

public:

	static BlockStack* GetInstance() {
		if (mInstance == 0) {
			mInstance = new BlockStack();
		}
		return mInstance;
	}

	/*
	블록 한 행이 모두 찬 경우 True 반환하고 점수 100점 올림.
	두 행이 가득차면 'Nice',
	세 행 이상 가득차면 'Excellent' 출력할 것.
	*/
	bool CheckRowFulled(sf::RenderWindow& window);


	/*
	현재까지 쌓인 블록들을 모두 draw함.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	UnitBlock GetOneBlock(int row, int column) { return mBlock[column][row]; }

	void OneBlockMark(int row, int column) { mBlock[column][row].BlockMark();  }

	void OneBlockSetSprite(int row, int column, sf::Sprite sprite) { mBlock[column][row].SetSprite(sprite); }

	bool BlockIsMarked(int row, int column) { return mBlock[column][row].IsMarked(); }

};

#endif