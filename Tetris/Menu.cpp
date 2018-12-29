#include "pch.h"

#include "Windows.h"
#undef min
#undef max

#include "SFML/Graphics.hpp"
#include "BlockStack.h"
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
	mMenuText[0].setString(L"계속");
	mMenuText[0].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[0].setPosition(sf::Vector2f(600, 250));

	mMenuText[1].setFont(mMenufont);
	mMenuText[1].setFillColor(DEFAULT_MENU_ITEM_COLOR);
	mMenuText[1].setString(L"다시 하기");
	mMenuText[1].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[1].setPosition(sf::Vector2f(600, 400));

	mMenuText[2].setFont(mMenufont);
	mMenuText[2].setFillColor(DEFAULT_MENU_ITEM_COLOR);
	mMenuText[2].setString(L"게임 종료");
	mMenuText[2].setCharacterSize(MENU_ITEM_SIZE);
	mMenuText[2].setPosition(sf::Vector2f(600, 550));

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

	BlockStack* bs = BlockStack::GetInstance();

	window.draw(mMenuSprite);
	bs->DrawBlockStacked(window);

	for (int i = 0; i < MAX_NUMBER_OF_MENU_ITEMS; i++)
	{
		window.draw(mMenuText[i]);
	}


}