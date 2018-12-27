#include "pch.h"

#include "BlockStack.h"
#include "Sound.h"

BlockStack* BlockStack::mInstance = nullptr;

BlockStack::BlockStack() {


	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++)

		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {

			// �� �� Sprite�鿡 ��ǥ �ο�
			mBlock[column][row].SetPosition
				(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
					BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * column);

			// �� �׵θ� ���鿡 Mark��. 
			if (row == 0 ||
				row == ROW_PIXEL_NUMBER - 1 ||
				column == COLUMN_PIXEL_NUMBER - 1)

				mBlock[column][row].BlockMark();

		}

}


/*
��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
�� ���� �������� 'Nice',
�� �� �̻� �������� 'Excellent' ����� ��.

�� ��Ģ ��ü�� ���߿� ������ �� �ֵ��� �� ��
*/
bool BlockStack::CheckRowFulled(sf::RenderWindow& window) {

	unsigned int count = 0;
	Sound* sc = Sound::GetInstance();

	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++) {

		count = 0;

		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {

			if (!mBlock[column][row].IsMarked()) count++;

			if (count == ROW_PIXEL_NUMBER) {


			}

		}
	}
}


/*
��� ��ϵ� �� Mark�� ��ϵ� (���� ���) �� Ž���ϰ�, draw��.
*/
void BlockStack::DrawBlockStacked(sf::RenderWindow& window) {

	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++)
		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {
			if (mBlock[column][row].IsMarked())
				window.draw(mBlock[column][row].GetSprite());
		}
}
