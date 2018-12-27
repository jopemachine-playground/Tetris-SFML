#include "pch.h"

#include "UnitBlock.h"
#include "GamePool.h"

UnitBlock::UnitBlock() {
		

}

void UnitBlock::SetPosition(int blockPixel_x, int blockPixel_y) {
	
	mSprite.setPosition(blockPixel_x, blockPixel_y);

	mPoint.IndexX = blockPixel_x / ONE_BLOCK_PIXEL;
	mPoint.IndexY = blockPixel_y / ONE_BLOCK_PIXEL;

}