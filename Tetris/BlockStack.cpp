#include "pch.h"

#include "BlockStack.h"
#include "Sound.h"
#include "Ranking.h"

#include <iostream>

BlockStack* BlockStack::mInstance = nullptr;

BlockStack::BlockStack() {

	GamePool* gp = GamePool::GetInstance();

	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++) {

		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {

			// 각 블럭 Sprite Color를 Default로 함
			if (row != 0 &&
				column != 0 &&
				row != ROW_PIXEL_NUMBER - 1 &&
				column != COLUMN_PIXEL_NUMBER - 1)

				mBlock[column][row].SetSprite(gp->GetBlockColorSprite(eBlockColor::Default));

			// 각 블럭 Sprite들에 좌표 부여
			mBlock[column][row].SetPosition
			(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
				BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * column);

			// 각 테두리 블럭들에 Mark함. 
			if (row == 0 ||
				row == ROW_PIXEL_NUMBER - 1 ||
				column == COLUMN_PIXEL_NUMBER - 1) {

				mBlock[column][row].BlockMark();

			}

		}

	}

}

/*
블록 한 행이 모두 찬 경우 True 반환하고 점수 100점 올림.
두 행이 가득차면 'Nice',
세 행 이상 가득차면 'Excellent' 출력할 것.

이 규칙 자체는 나중에 변경할 수 있도록 할 것
*/
void BlockStack::CheckRowFulled() {

	unsigned int count = 0;
	Sound* sc = Sound::GetInstance();
	Ranking* rk = Ranking::GetInstance();

	for (int column = COLUMN_PIXEL_NUMBER - 2; column > 0; column--) {

		count = 0;

		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			if (mBlock[column][row].IsMarked()) count++;

			// 한 Row가 완전히 비어 있다면 return
			// if (count == 0) return;

			// 한 Row가 다 차면 삭제
			if (count == ROW_PIXEL_NUMBER - 2) {

				sc->PlayBlockDelete();

				// 언마크된 row 위의 블록들을 아래로 내림.
				for (int deleteColumn = column; deleteColumn > 1; deleteColumn--) {

					for (int row2 = 1; row2 < ROW_PIXEL_NUMBER - 1; row2++) {

						mBlock[deleteColumn][row2].SetSprite(mBlock[deleteColumn - 1][row2].GetSprite());
						mBlock[deleteColumn][row2].BlockMove(0, ONE_BLOCK_PIXEL);
						mBlock[deleteColumn][row2].SetMark(mBlock[deleteColumn - 1][row2].IsMarked());

					}
				}
#ifdef DEBUG_CONSOLE
				DEBUG_CheckAllBlock();
#endif
			}

		}
	}
}

void BlockStack::DEBUG_CheckAllBlock() {

	std::cout << "##### Block Checker #####" << std::endl;

	for (int column = 1; column < COLUMN_PIXEL_NUMBER - 1; column++) {

		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			std::cout << mBlock[column][row].IsMarked() << " ";

		}
		std::cout << std::endl;
	}
	std::cout << "############################ " << std::endl;

	std::cout << std::endl;
}


/*
모든 블록들 중 Mark된 블록들 (쌓인 블록) 을 탐색하고, draw함.
*/
void BlockStack::DrawBlockStacked(sf::RenderWindow& window) {

	for (int column = 1; column < COLUMN_PIXEL_NUMBER - 1; column++)
		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			window.draw(mBlock[column][row].GetSprite());
		}
}
