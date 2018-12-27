#pragma once

#ifndef BLOCKSTACK_H
#define BLOCKSTACK_H

#include "UnitBlock.h"
#include "GamePool.h"

class BlockStack {

private:

	// ������ ��ġ�� ��Ÿ���� UnitBlock �迭
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
	��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
	�� ���� �������� 'Nice',
	�� �� �̻� �������� 'Excellent' ����� ��.
	*/
	bool CheckRowFulled(sf::RenderWindow& window);


	/*
	������� ���� ��ϵ��� ��� draw��.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	UnitBlock GetOneBlock(int row, int column) { return mBlock[column][row]; }

	void OneBlockMark(int row, int column) { mBlock[column][row].BlockMark();  }

	void OneBlockSetSprite(int row, int column, sf::Sprite sprite) { mBlock[column][row].SetSprite(sprite); }

	bool BlockIsMarked(int row, int column) { return mBlock[column][row].IsMarked(); }

};

#endif