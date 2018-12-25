#pragma once

#include "SFML/Graphics.hpp"

#include "UnitBlock.h"

class MovingBlock {

private:

	size_t mMovingTime = 0.5;

	const static size_t MAX_UNITBLOCK_NUMBER = 4;

	// ���� (���ϴ� ��ġ)�� UnitBlock���� �迭. �ִ� ������ 4.
	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	������ �� �ִ� ��ϵ��� ���.
	�� ���鿡 ���ؼ� blockshape ���� ����
	*/
	enum eBlockShape {

		I = 1,
		Z = 2,
		S = 3,
		T = 4,
		L = 5,
		J = 6,
		O = 7

	};

	/*
	������ ����� ���, ������ �������� ������ �Լ�.
	���� 7���� ��絵 7���淡 ���� �Լ��� �����
	*/
	const unsigned short GetRandomNumber();

public:

	MovingBlock();

	// �Ʒ� Ű �Է½� MovingTime ����, ���� �ݺ������� �ǵ���
	void SetMovingTime(const size_t time) { mMovingTime = time; }

	const size_t GetMovingTime() const { return mMovingTime; }

	/*
	CheckBlockBelow() �� True ��ȯ�ϸ� ����� �Ʒ��� �� �� �̵�
	*/
	void BlockMoveDownByTime();

	/*
	�Ʒ��� ����� �ִ��� üũ
	True�̸� ����� ���߰� ���� ����� ����.
	False�� ����� �Ʒ��� �� �� ����.
	*/
	bool CheckBlockBelow();

	/*
	main���� Ű �Է� �� ����� ����� ����
	*/
	void RotateBlock();

	// ����� Ű �Է����� �̵���Ŵ
	void BlockMoveLeft();
	void BlockMoveRight();

	void DrawMovingBlock(sf::RenderWindow& window);

};