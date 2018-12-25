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
	bool CheckOneRowFulled(sf::RenderWindow& window);


	/*
	������� ���� ��ϵ��� ��� draw��.
	*/
	void DrawBlockStacked(sf::RenderWindow& window);

	UnitBlock GetOneBlock(int row, int column) { return mBlock[column][row]; }

};

#endif