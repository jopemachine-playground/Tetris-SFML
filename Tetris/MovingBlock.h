#pragma once

#include <SFML/Graphics.hpp>

#include "UnitBlock.h"

class MovingBlock 
{

private:

	int mMovingTime = DEFAULT_BLOCK_MOVINGTIME;

	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	������ �� �ִ� ��ϵ��� ���.
	�� ���鿡 ���ؼ� blockshape ���� ����
	*/
	eBlockShape mBlockShape;

public:

	MovingBlock();

	MovingBlock(eBlockShape& shape, eBlockColor& color);

	// �Ʒ� Ű �Է½� MovingTime ����, ���� �ݺ������� �ǵ���
	void SetMovingTime(const float time) { mMovingTime = time; }

	const int GetMovingTime() const { return mMovingTime; }

	/*
	CheckBlockBelow() �� True ��ȯ�ϸ� ����� �Ʒ��� �� �� �̵�
	*/
	void BlockMoveDownByTime();

	/*
	����� �� ���⿡ ����� �ִ��� üũ
	True�̸� ����� ���߰� ���� ����� ����.
	False�� ����� �Ʒ��� �� �� ����.
	*/
	
	bool BlockReachBottom();


	/*
	main���� Ű �Է� �� ����� ����� ����
	*/
	void RotateBlock();

	// ����� Ű �Է����� �̵���Ŵ
	void BlockMoveLeft();
	void BlockMoveRight();

	void DrawMovingBlock(sf::RenderWindow& window);

};