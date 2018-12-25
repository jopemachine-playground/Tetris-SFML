#include "pch.h"

#include "BlockStack.h"

BlockStack* BlockStack::mInstance = nullptr;

BlockStack::BlockStack() {


	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++)

		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {

			// 각 블럭 Sprite들에 좌표 부여
			mBlock[column][row].GetSprite().
				setPosition
				(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
					BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * column);

			// 각 블럭들에 좌표 부여
			/*
			mBlock[column][row].
				SetPosition
				(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
					BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * column);
			*/
		}

}


/*
블록 한 행이 모두 찬 경우 True 반환하고 점수 100점 올림.
두 행이 가득차면 'Nice',
세 행 이상 가득차면 'Excellent' 출력할 것.

이 규칙 자체는 나중에 변경할 수 있도록 할 것
*/
bool BlockStack::CheckOneRowFulled(sf::RenderWindow& window) {

}


/*
모든 블록들 중 Mark된 블록들 (쌓인 블록) 을 탐색하고, draw함.
*/
void BlockStack::DrawBlockStacked(sf::RenderWindow& window) {

	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++)
		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {
			if (mBlock[column][row].IsMarked())
				window.draw(mBlock[column][row].GetSprite());
		}
}
