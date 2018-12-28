#include "pch.h"

#include "BlockStack.h"
#include "Sound.h"

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
	GamePool* gp = GamePool::GetInstance();

	for (int column = 1; column < COLUMN_PIXEL_NUMBER - 1; column++) {

		count = 0;

		for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

			if (mBlock[column][row].IsMarked()) count++;

			// �� Row�� �� ���� ����
			if (count == ROW_PIXEL_NUMBER - 2) {

				sc->PlayBlockDelete();

				// �ش� row�� ��ũ�ϰ�, default�� Sprite Change.
				for (int row = 1; row < ROW_PIXEL_NUMBER - 1; row++) {

					sf::Vector2f position = mBlock[column][row].GetPosition();
					mBlock[column][row].SetSprite(gp->GetBlockColorSprite(Default));
					mBlock[column][row].SetPosition(position.x, position.y);
					mBlock[column][row].BlockErase();
				}

				// ��ũ�� row �� row���� �Ʒ��� ����.
				for (int deleteColumn = column; deleteColumn < COLUMN_PIXEL_NUMBER; deleteColumn++) {
					mBlock[deleteColumn][row].SetSprite(mBlock[deleteColumn - 1][row].GetSprite());
				}


			}

		}
	}
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
