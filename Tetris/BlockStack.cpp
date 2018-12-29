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

			// �� �� Sprite Color�� Default�� ��
			if (row != 0 &&
				column != 0 &&
				row != ROW_PIXEL_NUMBER - 1 &&
				column != COLUMN_PIXEL_NUMBER - 1)

				mBlock[column][row].SetSprite(gp->GetBlockColorSprite(eBlockColor::Default));

			// �� �� Sprite�鿡 ��ǥ �ο�
			mBlock[column][row].SetPosition
			(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
				BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * column);

			// �� �׵θ� ���鿡 Mark��. 
			if (row == 0 ||
				row == ROW_PIXEL_NUMBER - 1 ||
				column == COLUMN_PIXEL_NUMBER - 1) {

				mBlock[column][row].BlockMark();

			}

		}

	}

}

/*
��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
�� ���� �������� 'Nice',
�� �� �̻� �������� 'Excellent' ����� ��.

�� ��Ģ ��ü�� ���߿� ������ �� �ֵ��� �� ��
*/
void BlockStack::CheckRowFulled() {

	unsigned int count = 0;
	Sound* sc = Sound::GetInstance();
	Ranking* rk = Ranking::GetInstance();

	for (int column = COLUMN_PIXEL_NUMBER - 2; column > 0; column--) {

		count = 0;

		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			if (mBlock[column][row].IsMarked()) count++;

			// �� Row�� ������ ��� �ִٸ� return
			// if (count == 0) return;

			// �� Row�� �� ���� ����
			if (count == ROW_PIXEL_NUMBER - 2) {

				sc->PlayBlockDelete();

				// ��ũ�� row ���� ��ϵ��� �Ʒ��� ����.
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
��� ��ϵ� �� Mark�� ��ϵ� (���� ���) �� Ž���ϰ�, draw��.
*/
void BlockStack::DrawBlockStacked(sf::RenderWindow& window) {

	for (int column = 1; column < COLUMN_PIXEL_NUMBER - 1; column++)
		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			window.draw(mBlock[column][row].GetSprite());
		}
}
