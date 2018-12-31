#pragma once

#ifndef BLOCKSTACK_H
#define BLOCKSTACK_H

#include "UnitBlock.h"
#include "GamePool.h"

class BlockStack
{

private:

	// ������ ��ġ�� ��Ÿ���� UnitBlock �迭
	UnitBlock mBlock[COLUMN_PIXEL_NUMBER][ROW_PIXEL_NUMBER];

	BlockStack();

	static BlockStack* mInstance;

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
	��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
	�� ���� �������� 'Nice',
	�� �� �̻� �������� 'Excellent' ����� ��.
	*/
	const bool CheckRowFulled();


	/*
	������� ���� ��ϵ��� ��� draw��.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	UnitBlock GetOneBlock(const int row, const int column) { return mBlock[column][row]; }

	const void OneBlockMark(const int row, const int column) { mBlock[column][row].BlockMark();  }

	const void OneBlockSetSprite(const int row, const int column, sf::Sprite sprite) { mBlock[column][row].SetSprite(sprite); }

	const bool BlockIsMarked(const int row, const int column) { return mBlock[column][row].IsMarked(); }

	const bool IsGameEnd();

	void DEBUG_CheckAllBlock();

};

#endif