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
	생성될 수 있는 블록들의 모양.
	각 모양들에 대해선 blockshape 폴더 참고
	*/
	eBlockShape mBlockShape;

	void decideBlockShape(eBlockShape& shape);

public:

	MovingBlock();

	MovingBlock(eBlockShape& shape, eBlockColor& color);

	// 아래 키 입력시 MovingTime 변경, 다음 반복문에서 되돌림
	void SetMovingTime(const float time) { mMovingTime = time; }

	const float GetMovingTime() const { return mMovingTime; }

	/*
	BlockReachBottom() 이 True 반환하면 블록을 아래로 한 열 이동
	*/
	void BlockMoveDownByTime();

	/*
	아래에 블록이 닿았는지 체크. 
	bMark가 true면 MovingBlock이 있었던 자리의 인덱스에 해당하는 BlockStack을 체크.
	리턴값이 True이면 블록을 멈추고 다음 블록을 생성.
	리턴값이 False면 블록을 아래로 한 열 내림.
	*/
	
	bool BlockReachBottom(const bool bMark);


	/*
	main에서 키 입력 시 블록의 모양을 변경
	*/
	void RotateBlock();

	// 블록을 키 입력으로 이동시킴
	void BlockMoveLeft();
	void BlockMoveRight();

	void DrawMovingBlock(sf::RenderWindow& window);

	void SetSprite(sf::Sprite sprite);

};