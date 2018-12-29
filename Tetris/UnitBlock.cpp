#include "pch.h"

#include "UnitBlock.h"
#include "GamePool.h"

UnitBlock::UnitBlock() 
{



}

void UnitBlock::SetPosition(int blockPixel_x, int blockPixel_y) 
{
	
	mSprite.setPosition(blockPixel_x, blockPixel_y);

	mPoint.IndexX = (blockPixel_x - BACKGROUND_POSITIONX) / ONE_BLOCK_PIXEL;
	mPoint.IndexY = (blockPixel_y - BACKGROUND_POSITIONY) / ONE_BLOCK_PIXEL;

}