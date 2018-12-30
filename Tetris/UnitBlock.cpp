#include "pch.h"

#include "UnitBlock.h"
#include "GamePool.h"

void UnitBlock::SetPosition(int blockPixel_x, int blockPixel_y) 
{
	
	mSprite.setPosition(blockPixel_x, blockPixel_y);

	mPoint.IndexX = (blockPixel_x - BACKGROUND_POSITIONX) / ONE_BLOCK_PIXEL;
	mPoint.IndexY = (blockPixel_y - BACKGROUND_POSITIONY) / ONE_BLOCK_PIXEL;

}

void UnitBlock::SetPositionByIndex(int index_x, int index_y) 
{
	mPoint.IndexX = index_x;
	mPoint.IndexY = index_y;

	mSprite.setPosition
	(BACKGROUND_POSITIONX + index_x * ONE_BLOCK_PIXEL, 
		BACKGROUND_POSITIONY + index_y * ONE_BLOCK_PIXEL);

}