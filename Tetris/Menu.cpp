#include "pch.h"

#include "Windows.h"
#undef min
#undef max

#include "SFML/Graphics.hpp"
#include "Sound.h"
#include "Menu.h"

/* 
	게임 플레이 중 게임 메뉴를 호출해 이용
	ESC : 게임 메뉴 호출
	Enter : 메뉴 선택
*/

Menu::Menu(const unsigned int pictureSelectedNumber) {

	mMenuTexture.loadFromFile("images/Picture" + std::to_string(pictureSelectedNumber) + ".png");
	mMenuSprite.setTexture(mMenuTexture);
	mMenuSprite.setPosition(0, 0);

	mMenufont.loadFromFile(FILE_STARTMENU_FONT);

	mMenuText[0].setFont(mMenufont);
	mMenuText[0].setFillColor(DEFAULT_MENU_ITEM_COLOR);
	mMenuText[0].setString("Continue");
	mMenuText[0].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[0].setPosition(sf::Vector2f(550, 300));

	mMenuText[1].setFont(mMenufont);
	mMenuText[1].setFillColor(DEFAULT_MENU_ITEM_COLOR);
	mMenuText[1].setString("Options");
	mMenuText[1].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[1].setPosition(sf::Vector2f(550, 450));

	mMenuText[2].setFont(mMenufont);
	mMenuText[2].setFillColor(DEFAULT_MENU_ITEM_COLOR);
	mMenuText[2].setString("Exit");
	mMenuText[2].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[2].setPosition(sf::Vector2f(550, 600));

	mMenuText[mSelectedItemIndex].setFillColor(SELECTED_MENU_ITEM_COLOR);
}

void Menu::MoveUp() {

	Sound* sc = Sound::GetInstance();

	mMenuText[mSelectedItemIndex].setFillColor(DEFAULT_MENU_ITEM_COLOR);

	if (mSelectedItemIndex <= 0) mSelectedItemIndex = MAX_NUMBER_OF_MENU_ITEMS - 1;
	else mSelectedItemIndex--;

	mMenuText[mSelectedItemIndex].setFillColor(SELECTED_MENU_ITEM_COLOR);
	sc->PlayMenuItemUpDown();
	Sleep(120);
}

void Menu::MoveDown() {

	Sound* sc = Sound::GetInstance();

	mMenuText[mSelectedItemIndex].setFillColor(DEFAULT_MENU_ITEM_COLOR);

	if (mSelectedItemIndex >= MAX_NUMBER_OF_MENU_ITEMS - 1) mSelectedItemIndex = 0;
	else mSelectedItemIndex++;

	mMenuText[mSelectedItemIndex].setFillColor(SELECTED_MENU_ITEM_COLOR);

	sc->PlayMenuItemUpDown();
	Sleep(120);
}

const void Menu::Draw(sf::RenderWindow& window) {

	window.draw(mMenuSprite);

	for (int i = 0; i < MAX_NUMBER_OF_MENU_ITEMS; i++)
	{
		window.draw(mMenuText[i]);
	}

}