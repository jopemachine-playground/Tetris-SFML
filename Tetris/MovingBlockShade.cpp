#include "pch.h"

#include "BlockStack.h"
#include "GamePool.h"
#include "MovingBlockShade.h"

MovingBlockShade::MovingBlockShade()
{

	if (!mBlockTransparentTexture.loadFromFile("images/transparent.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/default.png" << std::endl;
	}

	mBlockTransparentSprite.setTexture(mBlockTransparentTexture);

	mMovingBlock.SetSprite(mBlockTransparentSprite);

}

void MovingBlockShade::UpdateBlockShade(MovingBlock& movingBlock)
{

	mMovingBlock = movingBlock;

	mMovingBlock.SetSprite(mBlockTransparentSprite);

	while (!mMovingBlock.BlockReachBottom(false))
	{
		mMovingBlock.BlockMoveDownByTime();
	}

}

void MovingBlockShade::DrawMovingBlockShade(sf::RenderWindow& window)
{
	mMovingBlock.DrawMovingBlock(window);
}