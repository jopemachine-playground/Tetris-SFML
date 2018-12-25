#include "pch.h"

#include "BlockStack.h"

BlockStack* BlockStack::mInstance = nullptr;

BlockStack::BlockStack() {


	for (int column = 0; column < COLUMN_PIXEL_NUMBER; column++)

		for (int row = 0; row < ROW_PIXEL_NUMBER; row++) {

			// �� �� Sprite�鿡 ��ǥ �ο�
			mBlock[column][row].GetSprite().
				setPosition
				(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
					BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * column);

			// �� ���鿡 ��ǥ �ο�
			/*
			mBlock[column][row].
				SetPosition
				(BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * row,
					BACKGROUND_POSITIONX + ONE_BLOCK_PIXEL * column);
			*/
		}

}


/*
��� �� ���� ��� �� ��� True ��ȯ�ϰ� ���� 100�� �ø�.
�� ���� �������� 'Nice',
�� �� �̻� �������� 'Excellent' ����� ��.

�� ��Ģ ��ü�� ���߿� ������ �� �ֵ��� �� ��
*/
bool BlockStack::CheckOneRowFulled(sf::RenderWindow& window) {

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
