#pragma once

#include <SFML/Graphics.hpp>

class IMenu {

public:
	
	/*
	IMenu를 상속하는 Menu 클래스들은 아래의 함수들을 구현해야만 한다.
	*/

	virtual const void Draw(sf::RenderWindow& window) = 0;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual const int GetSelectedItemIndex() = 0;

};