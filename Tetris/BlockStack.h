#pragma once

#include "UnitBlock.h"
#include "GamePool.h"

class BlockStack
{
	friend MovingBlock;

private:

	// ������ ��ġ�� ��Ÿ���� UnitBlock �迭
	UnitBlock mBlock[COLUMN_PIXEL_NUMBER][ROW_PIXEL_NUMBER];

	BlockStack();

	static BlockStack* mInstance;

	// MovingBlock�� ���� ������ �޼���
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
	��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
	�� ���� �������� 'Nice',
	�� �� �̻� �������� 'Excellent' ����� ��.
	*/
	const bool CheckRowFulled();

	/*
	������� ���� ��ϵ��� ��� draw��.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	const bool IsGameEnd();

	void DEBUG_CheckAllBlock();

};
