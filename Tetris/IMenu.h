#pragma once

#include <SFML/Graphics.hpp>

class IMenu {

public:
	
	/*
	IMenu�� ����ϴ� Menu Ŭ�������� �Ʒ��� �Լ����� �����ؾ߸� �Ѵ�.
	*/

	virtual const void Draw(sf::RenderWindow& window) = 0;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual const int GetSelectedItemIndex() = 0;

};