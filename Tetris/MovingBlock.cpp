#include "pch.h"

#include <time.h>
#include <random>

#include "BlockStack.h"
#include "MovingBlock.h"

#include <iostream>

MovingBlock::MovingBlock() {

	GamePool* gp = GamePool::GetInstance();

	switch (GetRandomColor()) {

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


	switch (GetRandomShape()) {

	case eBlockShape::I: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 3 * ONE_BLOCK_PIXEL);

		break;
	}
	case eBlockShape::Z: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}
	case eBlockShape::S: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}
	case eBlockShape::T: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::L: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::J: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x - ONE_BLOCK_PIXEL, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::O: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);

		break;
	}
	}

}

const int MovingBlock::GetRandomShape() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(1, BLOCK_SHAPE_NUMBER);

	return dist(gen);

}

const int MovingBlock::GetRandomColor() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(1, BLOCK_COLOR_NUMBER);

	return dist(gen);

}

void MovingBlock::BlockMoveDownByTime() {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		mMovingUnitBlock[i].BlockMove(0, ONE_BLOCK_PIXEL);
	}

}

bool MovingBlock::CheckBlockBelow() {

	BlockStack *bs = BlockStack::GetInstance();

	//bs->mBlock[][]

	return false;

}

bool MovingBlock::CheckBlockLeft() {

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

	}

	return false;

}

bool MovingBlock::CheckBlockRight() {

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		
	}

	return false;

}

void MovingBlock::RotateBlock() {



}



void MovingBlock::BlockMoveLeft() {

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		if (bs->BlockIsMarked((mMovingUnitBlock[i].GetIndexX()) -1, mMovingUnitBlock[i].GetIndexY()))
			return;

		mMovingUnitBlock[i].BlockMove((-1) * static_cast<int>(ONE_BLOCK_PIXEL), 0);
		mMovingUnitBlock[i].AddIndexX(-1);
	}

}

void MovingBlock::BlockMoveRight() {

	BlockStack *bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {

		if (bs->BlockIsMarked(mMovingUnitBlock[i].GetIndexX() +1, mMovingUnitBlock[i].GetIndexY()))
			return;

		mMovingUnitBlock[i].BlockMove(ONE_BLOCK_PIXEL, 0);
		mMovingUnitBlock[i].AddIndexX(1);
	}

}

void MovingBlock::DrawMovingBlock(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		window.draw(mMovingUnitBlock[i].GetSprite());
	}
}
