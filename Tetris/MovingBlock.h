#pragma once

#include <SFML/Graphics.hpp>

#include "NextBlock.h"
#include "UnitBlock.h"

class MovingBlock 
{

private:

	float mMovingTime = DEFAULT_BLOCK_MOVINGTIME;

	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	������ �� �ִ� ��ϵ��� ���.
	�� ���鿡 ���ؼ� blockshape ���� ����
	*/
	eBlockShape mBlockShape;

	void decideBlockShape(eBlockShape& shape);

public:

	MovingBlock();

	MovingBlock(eBlockShape& shape, eBlockColor& color);

	// �Ʒ� Ű �Է½� MovingTime ����, ���� �ݺ������� �ǵ���
	void SetMovingTime(const float time) { mMovingTime = time; }

	const float GetMovingTime() const { return mMovingTime; }

	/*
	BlockReachBottom() �� True ��ȯ�ϸ� ����� �Ʒ��� �� �� �̵�
	*/
	void BlockMoveDownByTime();

	/*
	�Ʒ��� ����� ��Ҵ��� üũ. 
	bMark�� true�� MovingBlock�� �־��� �ڸ��� �ε����� �ش��ϴ� BlockStack�� üũ.
	���ϰ��� True�̸� ����� ���߰� ���� ����� ����.
	���ϰ��� False�� ����� �Ʒ��� �� �� ����.
	*/
	
	bool BlockReachBottom(const bool bMark);


	/*
	main���� Ű �Է� �� ����� ����� ����
	*/
	void RotateBlock();

	// ����� Ű �Է����� �̵���Ŵ
	void BlockMoveLeft();
	void BlockMoveRight();

	void DrawMovingBlock(sf::RenderWindow& window);

	void SetSprite(sf::Sprite sprite);

};