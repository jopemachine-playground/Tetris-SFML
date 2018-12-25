#pragma once

#include "SFML/Graphics.hpp"

#include "UnitBlock.h"

class MovingBlock {

private:

	size_t mMovingTime = 0.5;

	const static size_t MAX_UNITBLOCK_NUMBER = 4;

	// 동적 (변하는 위치)인 UnitBlock들의 배열. 최대 갯수는 4.
	UnitBlock mMovingUnitBlock[MAX_UNITBLOCK_NUMBER];

	eBlockColor mMovingBlockColor;

	/*
	생성될 수 있는 블록들의 모양.
	각 모양들에 대해선 blockshape 폴더 참고
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
	내려올 블록의 모양, 색깔을 랜덤으로 결정할 함수.
	색깔도 7개고 모양도 7개길래 같은 함수를 사용함
	*/
	const unsigned short GetRandomNumber();

public:

	MovingBlock();

	// 아래 키 입력시 MovingTime 변경, 다음 반복문에서 되돌림
	void SetMovingTime(const size_t time) { mMovingTime = time; }

	const size_t GetMovingTime() const { return mMovingTime; }

	/*
	CheckBlockBelow() 이 True 반환하면 블록을 아래로 한 열 이동
	*/
	void BlockMoveDownByTime();

	/*
	아래에 블록이 있는지 체크
	True이면 블록을 멈추고 다음 블록을 생성.
	False면 블록을 아래로 한 열 내림.
	*/
	bool CheckBlockBelow();

	/*
	main에서 키 입력 시 블록의 모양을 변경
	*/
	void RotateBlock();

	// 블록을 키 입력으로 이동시킴
	void BlockMoveLeft();
	void BlockMoveRight();

	void DrawMovingBlock(sf::RenderWindow& window);

};