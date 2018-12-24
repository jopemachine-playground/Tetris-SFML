#pragma once

#ifndef STARTMENU_HPP
#define STARTMENU_HPP

#include "SFML/Graphics.hpp"
#include "Game.h"

class StartMenu{

private:

	const static int MAX_NUMBER_OF_STARTMENU_ITEMS = 3;
	const static size_t MENU_ITEM_SIZE = 70;
	const sf::Color DEFAULT_STARTMENU_ITEM_COLOR = sf::Color::White;
	const sf::Color SELECTED_STARTMENU_ITEM_COLOR = sf::Color::Cyan;
	const sf::Color GAME_TITLE_COLOR = sf::Color::White;

	sf::Texture mStartMenuTexture;
	sf::Sprite mStartMenuSprite;

	sf::Font mMenufont;
	sf::Font mGameTitleFont;
	sf::Text mGameTitle;
	sf::Text mStartMenuText[MAX_NUMBER_OF_STARTMENU_ITEMS];

	int mSelectedItemIndex = 0;

public:

	enum {
		BUTTON_PLAY = 0,
		BUTTON_OPTION = 1,
		BUTTON_QUIT = 2
	};

	StartMenu(float width, float height);
	void MoveUp();
	void MoveDown();
	const int GetSelectedItemIndex() { return mSelectedItemIndex; }
	const void Draw(sf::RenderWindow& window);

};






#endif