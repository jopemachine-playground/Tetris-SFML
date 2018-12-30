#include "pch.h"

#include <time.h>
#include <random>

#include "BlockStack.h"
#include "MovingBlock.h"
#include "Sound.h"

#include <iostream>

/*
����� �ٴڿ� ���� �� ���� ���� ȣ��Ǿ� �� �����̴� ����� ����.
*/
MovingBlock::MovingBlock() 
{

	GamePool* gp = GamePool::GetInstance();

	switch (GetRandomColor()) 
	{

	case Red: { mMovingBlockColor = Red; break; }
	case Skyblue: { mMovingBlockColor = Skyblue; break; }
	case Yellow: { mMovingBlockColor = Yellow; break; }
	case Purple: { mMovingBlockColor = Purple; break; }
	case Orange: { mMovingBlockColor = Orange; break; }
	case Green: { mMovingBlockColor = Green; break; }
	case Blue: { mMovingBlockColor = Blue; break; }

	}

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		mMovingUnitBlock[i].SetSprite(gp->GetBlockColorSprite(mMovingBlockColor));
	}


	/*
	7�� ����� ����� ����. ��ϵ��� ��� 4���� UnitBlock���� �̷��� �ְ�,
	��ȣ�� ������ �Ʒ���, ���ʿ��� ���������� 1�� ���.
	1�� ��� (ȸ���� �߽�) �� BlockGenerate ���� ������.
	*/

	switch (GetRandomShape()) 
	{

	case eBlockShape::I:
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 3 * ONE_BLOCK_PIXEL);

		mBlockShape = I;
		break;
	}

	case eBlockShape::Z: 
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		mBlockShape = Z;
		break;
	}

	case eBlockShape::S: 
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		mBlockShape = S;
		break;
	}

	case eBlockShape::T: 
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		mBlockShape = T;
		break;
	}

	case eBlockShape::L:
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		mBlockShape = L;
		break;
	}

	case eBlockShape::J: 
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		mBlockShape = J;
		break;
	}

	case eBlockShape::O:
	{

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);

		mBlockShape = O;
		break;
	}

	}

}

const int MovingBlock::GetRandomShape()
{

	std::random_device rd;  
	std::mt19937 gen(rd());   
	std::uniform_int_distribution<> dist(0, BLOCK_SHAPE_NUMBER - 1);

	return dist(gen);
}

const int MovingBlock::GetRandomColor() 
{

	std::random_device rd;  
	std::mt19937 gen(rd());   
	std::uniform_int_distribution<> dist(0, BLOCK_COLOR_NUMBER - 1);

	return dist(gen);

}

void MovingBlock::BlockMoveDownByTime() 
{

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = MAX_UNITBLOCK_NUMBER - 1; i >= 0; i--) {

		if (bs->
			BlockIsMarked(
			(mMovingUnitBlock[i].GetIndexX()),
				mMovingUnitBlock[i].GetIndexY() + 1))
			return;
	}

	for (int i = MAX_UNITBLOCK_NUMBER - 1; i >= 0; i--) {
		mMovingUnitBlock[i].BlockMove(0, ONE_BLOCK_PIXEL);
		mMovingUnitBlock[i].AddIndexY(1);
	}

}

/*
����� �ٴڿ� ���� �� ���� ȣ��Ǿ� MovingBlock�� ������
BlockStack�� �ѱ�
*/

bool MovingBlock::BlockReachBottom() 
{

	BlockStack *bs = BlockStack::GetInstance();
	int x, y;
	for (int i = MAX_UNITBLOCK_NUMBER - 1; i >= 0; i--) {

		x = mMovingUnitBlock[i].GetIndexX();
		y = mMovingUnitBlock[i].GetIndexY();

		if (bs->BlockIsMarked(x, y + 1)) {

			for (int i = MAX_UNITBLOCK_NUMBER - 1; i >= 0; i--) {

				x = mMovingUnitBlock[i].GetIndexX();
				y = mMovingUnitBlock[i].GetIndexY();

				bs->OneBlockMark(x, y);
				bs->OneBlockSetSprite(x, y, mMovingUnitBlock[i].GetSprite());

			}
			return true;
		}
	}
	return false;
}


/*
����� �켱 �������� �� �� ȸ����Ŵ. ȸ���� [1]�� ����� �߽����� ��.
([0]�� ����� �߽����� ȸ�� ��Ű�� y��ǥ�� 1�� ����ϰ�, 2,3���� �߽����� �ϸ� �����ϱ� ������ [1]�� ����� �߽����� ������)

ȸ���� �� �ش� ��ǥ�� BlockStack�� ����� ��ũ�Ǿ� �ִٸ� ȸ���� ����� ������Ű�� ����
*/

void MovingBlock::RotateBlock() 
{

	Sound *sc = Sound::GetInstance();
	BlockStack* bs = BlockStack::GetInstance();

	int prev_X[MAX_UNITBLOCK_NUMBER], prev_Y[MAX_UNITBLOCK_NUMBER];
	int after_X[MAX_UNITBLOCK_NUMBER], after_Y[MAX_UNITBLOCK_NUMBER];

	int rotateCenter_X = mMovingUnitBlock[1].GetIndexX();
	int rotateCenter_Y = mMovingUnitBlock[1].GetIndexY();

	// ȸ���� ���� �������� ���� �� ȸ��. (���������� �ε����� ���� ����)
	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++)
	{
		prev_X[i] = mMovingUnitBlock[i].GetIndexX() - rotateCenter_X;
		prev_Y[i] = mMovingUnitBlock[i].GetIndexY() - rotateCenter_Y;

		after_X[i] = (-1) * prev_Y[i] + rotateCenter_X;
		after_Y[i] = prev_X[i] + rotateCenter_Y;

		// ȸ���� �������� ����

		if (bs->BlockIsMarked(after_X[i], after_Y[i]) || mBlockShape == O)
		{
			// ����
			return;
		}

	}

	sc->PlayRotateKeyClicked();

	// Sprite���� ȸ��
	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++)
	{
		mMovingUnitBlock[i].SetPositionByIndex(after_X[i], after_Y[i]);
	}

}

void MovingBlock::BlockMoveLeft() 
{

	Sound *sc = Sound::GetInstance();

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		if (bs->BlockIsMarked((mMovingUnitBlock[i].GetIndexX()) - 1, mMovingUnitBlock[i].GetIndexY()))
			return;
	}

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		sc->PlayBlockMove();
		mMovingUnitBlock[i].BlockMove((-1) * static_cast<int>(ONE_BLOCK_PIXEL), 0);
		mMovingUnitBlock[i].AddIndexX(-1);

	}

}

void MovingBlock::BlockMoveRight()
{

	Sound *sc = Sound::GetInstance();

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		if (bs->BlockIsMarked(mMovingUnitBlock[i].GetIndexX() + 1, mMovingUnitBlock[i].GetIndexY()))
			return;
	}

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		sc->PlayBlockMove();
		mMovingUnitBlock[i].BlockMove(ONE_BLOCK_PIXEL, 0);
		mMovingUnitBlock[i].AddIndexX(1);
	}

}

void MovingBlock::DrawMovingBlock(sf::RenderWindow& window)
{

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		window.draw(mMovingUnitBlock[i].GetSprite());
	}
}
