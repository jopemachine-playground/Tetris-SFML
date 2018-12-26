#pragma once

#include "SFML/Graphics.hpp"

#include "UnitBlock.h"

class MovingBlock {

private:

	float mMovingTime;

	const static size_t MAX_UNITBLOCK_NUMBER = 4;

	// ���� (���ϴ� ��ġ)�� UnitBlock���� �迭. �ִ� ������ 4.
	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	������ �� �ִ� ���ϵ��� ���.
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
	������ ������ ���, ������ �������� ������ �Լ�.
	���� 7���� ��絵 7���淡 ���� �Լ��� �����
	*/
	const int GetRandomNumber();

public:

	MovingBlock();

	// �Ʒ� Ű �Է½� MovingTime ����, ���� �ݺ������� �ǵ���
	void SetMovingTime(const float time) { mMovingTime = time; }

	const float GetMovingTime() const { return mMovingTime; }

	/*
	CheckBlockBelow() �� True ��ȯ�ϸ� ������ �Ʒ��� �� �� �̵�
	*/
	void BlockMoveDownByTime();

	/*
	�Ʒ��� ������ �ִ��� üũ
	True�̸� ������ ���߰� ���� ������ ����.
	False�� ������ �Ʒ��� �� �� ����.
	*/
	bool CheckBlockBelow();

	/*
	main���� Ű �Է� �� ������ ����� ����
	*/
	void RotateBlock();

	// ������ Ű �Է����� �̵���Ŵ
	void BlockMoveLeft();
	void BlockMoveRight();
	

	void DrawMovingBlock(sf::RenderWindow& window);

};