#pragma once

#include <SFML/Graphics.hpp>

#include "UnitBlock.h"

class MovingBlock 
{

private:

	int mMovingTime = DEFAULT_BLOCK_MOVINGTIME;

	const static size_t MAX_UNITBLOCK_NUMBER = 4;

	// ���� (���ϴ� ��ġ)�� UnitBlock���� �迭. �ִ� ������ 4.
	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	������ �� �ִ� ��ϵ��� ���.
	�� ���鿡 ���ؼ� blockshape ���� ����
	*/
	enum eBlockShape {

		I = 0,
		Z = 1,
		S = 2,
		T = 3,
		L = 4,
		J = 5,
		O = 6

	};

	/*
	������ ����� ���, ������ �������� ������ �Լ�.
	*/
	const int GetRandomShape();
	const int GetRandomColor();

public:

	MovingBlock();

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