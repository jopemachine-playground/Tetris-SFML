#include "pch.h"

#include <time.h>
#include <random>

#include "BlockStack.h"
#include "MovingBlock.h"


#include <iostream>

MovingBlock::MovingBlock() {

	GamePool* gp = GamePool::GetInstance();

	switch (GetRandomNumber()) {

	case Red: { mMovingBlockColor = Red; break; }
	case Skyblue: { mMovingBlockColor = Skyblue; break; }
	case Yellow: { mMovingBlockColor = Yellow; break; }
	case Purple: { mMovingBlockColor = Purple; break; }
	case Orange: { mMovingBlockColor = Orange; break; }
	case Green: { mMovingBlockColor = Green; break; }
	case Blue: {mMovingBlockColor = Blue; break; }

	}

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		mMovingUnitBlock[i].SetSprite(gp->GetBlockColorSprite(mMovingBlockColor));
	}


	switch (GetRandomNumber()) {

	case eBlockShape::I: {

		mMovingUnitBlock[0].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y);
		mMovingUnitBlock[1].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + 3 * ONE_BLOCK_PIXEL);

		std::cout << "1 OK" << std::endl;
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

		std::cout << "2 OK" << std::endl;
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

		std::cout << "3 OK" << std::endl;
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

		std::cout << "4 OK" << std::endl;
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

		std::cout << "5 OK" << std::endl;
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

		std::cout << "6 OK" << std::endl;
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
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + 2 * ONE_BLOCK_PIXEL);

		std::cout << "7 OK p" << std::endl;
		break;
	}
	}


	// std::cout << BlockGeneratePoint.x; => OK
	// std::cout << BlockGeneratePoint.y; => OK
}

const int MovingBlock::GetRandomNumber() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(1, BLOCK_COLOR_NUMBER);

	//return dist(gen);
	return 5;

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

void MovingBlock::RotateBlock() {



}



void MovingBlock::BlockMoveLeft() {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		mMovingUnitBlock[i].BlockMove((-1) * (int)ONE_BLOCK_PIXEL, 0);
	}

}

void MovingBlock::BlockMoveRight() {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		mMovingUnitBlock[i].BlockMove(ONE_BLOCK_PIXEL, 0);
	}

}

void MovingBlock::DrawMovingBlock(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		window.draw(mMovingUnitBlock[i].GetSprite());
	}
}