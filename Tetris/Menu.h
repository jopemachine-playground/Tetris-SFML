#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GamePool.h"

class Menu 
{

private:

	const static int MAX_NUMBER_OF_MENU_ITEMS = 3;
	const static size_t MENU_ITEM_SIZE = 100;
	const sf::Color DEFAULT_MENU_ITEM_COLOR = sf::Color::Black;
	const sf::Color SELECTED_MENU_ITEM_COLOR = sf::Color::Cyan;

	sf::Texture mMenuTexture;
	sf::Sprite mMenuSprite;

	sf::Font mMenufont;

	sf::Text mMenuText[MAX_NUMBER_OF_MENU_ITEMS];

	int mSelectedItemIndex = 0;

public:

	enum 
	{
		BUTTON_PLAY = 0,
		BUTTON_GAME_RESTART = 1,
		BUTTON_QUIT = 2
	};

	Menu(const unsigned int pictureSelectedNumber);
	const void Draw(sf::RenderWindow& window);

	void MoveUp();
	void MoveDown();
	const int GetSelectedItemIndex() { return mSelectedItemIndex; }

};




#endif
