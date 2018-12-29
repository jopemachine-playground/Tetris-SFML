#include "pch.h"

#include <time.h>
#include <random>

#include "BlockStack.h"
#include "MovingBlock.h"
#include "Sound.h"

#include <iostream>

/*
블록이 바닥에 닿을 때 마다 새로 호출되어 새 움직이는 블록을 만듬.
*/
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


	/*
	7개 모양의 블록을 만듬. 블록들은 모두 4개의 UnitBlock으로 이뤄져 있음
	*/

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
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
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
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y);
		mMovingUnitBlock[2].SetPosition
		(BlockGeneratePoint.x, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(BlockGeneratePoint.x + ONE_BLOCK_PIXEL, BlockGeneratePoint.y + ONE_BLOCK_PIXEL);

		break;
	}
	}

}

const int MovingBlock::GetRandomShape() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(0, BLOCK_SHAPE_NUMBER - 1);

	return dist(gen);

}

const int MovingBlock::GetRandomColor() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(0, BLOCK_COLOR_NUMBER - 1);

	return dist(gen);

}

void MovingBlock::BlockMoveDownByTime() {

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
블록이 바닥에 닿을 때 마다 호출되어 MovingBlock의 정보를
BlockStack에 넘김
*/

bool MovingBlock::BlockReachBottom() {

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
#ifdef DEBUG_CONSOLE
			bs->DEBUG_CheckAllBlock();
#endif
			return true;
		}
	}
	return false;
}


/*
블록을 우선 왼쪽으로 한 번 회전시킴. 회전은 [1]번 블록을 중심으로 함.
([0]번 블록을 중심으로 회전 시키면 y좌표가 1씩 상승하고, 2,3번을 중심으로 하면 감소하기 때문에 [1]번 블록이 중심으로 적절함)

회전된 후 해당 좌표의 BlockStack의 블록이 마크되어 있다면 회전된 블록을 복구시키고 리턴
*/

void MovingBlock::RotateBlock() {

	UnitBlock temp[MAX_UNITBLOCK_NUMBER];

	Sound *sc = Sound::GetInstance();
	BlockStack* bs = BlockStack::GetInstance();

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++)
	{
		// mMovingUnitBlock[i].SetPosition();



		if (bs->BlockIsMarked
			(mMovingUnitBlock[i].GetIndexX(),
				mMovingUnitBlock[i].GetIndexY()))
		{
			// 복귀
			return;
		}

		sc->PlayRotateKeyClicked();

	}
}



void MovingBlock::BlockMoveLeft() {

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

void MovingBlock::BlockMoveRight() {

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

void MovingBlock::DrawMovingBlock(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++) {
		window.draw(mMovingUnitBlock[i].GetSprite());
	}
}
