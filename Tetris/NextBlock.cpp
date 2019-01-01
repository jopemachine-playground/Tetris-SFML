#include "pch.h"

#include <random>
#include "NextBlock.h"

const int NextBlock::getRandomShape()
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, BLOCK_SHAPE_NUMBER - 1);

	return dist(gen);
}

const int NextBlock::getRandomColor()
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, BLOCK_COLOR_NUMBER - 2);

	return dist(gen);

}

NextBlock::NextBlock()
{
	GamePool* gp = GamePool::GetInstance();

	mMovingBlockColor = static_cast<eBlockColor>(getRandomColor());
	mBlockShape = static_cast<eBlockShape>(getRandomShape());

	switch (mMovingBlockColor)
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
	7개 모양의 블록을 만듬. 블록들은 모두 4개의 UnitBlock으로 이뤄져 있고,
	번호는 위에서 아래로, 왼쪽에서 오른쪽으로 1씩 상승.
	1번 블록 (회전의 중심) 이 BlockGenerate 에서 생성됨.
	*/

	switch (mBlockShape)
	{

	case eBlockShape::I:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x - 15, NextBlockPoint.y - 25);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x - 15, NextBlockPoint.y + ONE_BLOCK_PIXEL - 25);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x - 15, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL - 25);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x - 15, NextBlockPoint.y + 3 * ONE_BLOCK_PIXEL - 25);

		break;
	}

	case eBlockShape::Z:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x - ONE_BLOCK_PIXEL, NextBlockPoint.y);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x - ONE_BLOCK_PIXEL, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::S:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x + ONE_BLOCK_PIXEL - 20, NextBlockPoint.y);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x - 20, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x - 20 + ONE_BLOCK_PIXEL, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x - 20, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::T:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x - ONE_BLOCK_PIXEL, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::L:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x - ONE_BLOCK_PIXEL, NextBlockPoint.y);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::J:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + ONE_BLOCK_PIXEL);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x - ONE_BLOCK_PIXEL, NextBlockPoint.y + 2 * ONE_BLOCK_PIXEL);

		break;
	}

	case eBlockShape::O:
	{

		mMovingUnitBlock[0].SetPosition
		(NextBlockPoint.x - 30, NextBlockPoint.y + 15);
		mMovingUnitBlock[1].SetPosition
		(NextBlockPoint.x + ONE_BLOCK_PIXEL - 30, NextBlockPoint.y + 15);
		mMovingUnitBlock[2].SetPosition
		(NextBlockPoint.x - 30, NextBlockPoint.y + ONE_BLOCK_PIXEL + 15);
		mMovingUnitBlock[3].SetPosition
		(NextBlockPoint.x + ONE_BLOCK_PIXEL - 30, NextBlockPoint.y + ONE_BLOCK_PIXEL + 15);

		break;
	}
	}
}

void NextBlock::DrawNextBlock(sf::RenderWindow& window)
{

	for (int i = 0; i < MAX_UNITBLOCK_NUMBER; i++)
	{
		window.draw(mMovingUnitBlock[i].GetSprite());
	}

}