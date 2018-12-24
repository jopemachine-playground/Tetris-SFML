#include "pch.h"

#include "Windows.h"
#undef min
#undef max

#include "Sound.h"
#include "StartMenu.h"

StartMenu::StartMenu(float width, float height) {

	mStartMenuTexture.loadFromFile("images/StartMenu.png");
	mStartMenuSprite.setTexture(mStartMenuTexture);
	mStartMenuSprite.setPosition(0, 0);

	mMenufont.loadFromFile(FILE_STARTMENU_FONT);
	mGameTitleFont.loadFromFile(FILE_STARTMENU_TITLE_FONT);

	mStartMenuText[0].setFont(mMenufont);
	mStartMenuText[0].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);
	mStartMenuText[0].setString("Play");
	mStartMenuText[0].setCharacterSize(MENU_ITEM_SIZE);
	mStartMenuText[0].setPosition(sf::Vector2f(100, 420));

	mStartMenuText[1].setFont(mMenufont);
	mStartMenuText[1].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);
	mStartMenuText[1].setString("Options");
	mStartMenuText[1].setCharacterSize(MENU_ITEM_SIZE);
	mStartMenuText[1].setPosition(sf::Vector2f(100, 490));

	mStartMenuText[2].setFont(mMenufont);
	mStartMenuText[2].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);
	mStartMenuText[2].setString("Exit");
	mStartMenuText[2].setCharacterSize(MENU_ITEM_SIZE);
	mStartMenuText[2].setPosition(sf::Vector2f(100, 560));

	mGameTitle.setFont(mGameTitleFont);
	mGameTitle.setString("Tetris!");
	mGameTitle.setFillColor(GAME_TITLE_COLOR);
	mGameTitle.setCharacterSize(110);
	mGameTitle.setPosition(sf::Vector2f(150, 100));

}

void StartMenu::MoveUp() {

	Sound* sc = Sound::getInstance();

	mStartMenuText[mSelectedItemIndex].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);

	if (mSelectedItemIndex <= 0) mSelectedItemIndex = MAX_NUMBER_OF_STARTMENU_ITEMS - 1;
	else mSelectedItemIndex--;
	
	mStartMenuText[mSelectedItemIndex].setFillColor(SELECTED_STARTMENU_ITEM_COLOR);
	sc->PlayMenuItemUpDown();
	Sleep(120);
}

void StartMenu::MoveDown() {

	Sound* sc = Sound::getInstance();

	mStartMenuText[mSelectedItemIndex].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);

	if (mSelectedItemIndex >= MAX_NUMBER_OF_STARTMENU_ITEMS - 1) mSelectedItemIndex = 0;
	else mSelectedItemIndex++;

	mStartMenuText[mSelectedItemIndex].setFillColor(SELECTED_STARTMENU_ITEM_COLOR);

	sc->PlayMenuItemUpDown();
	Sleep(120);
}

const void StartMenu::Draw(sf::RenderWindow& window) {

	window.draw(mStartMenuSprite);

	window.draw(mGameTitle);

	for (int i = 0; i < MAX_NUMBER_OF_STARTMENU_ITEMS; i++)
	{
		window.draw(mStartMenuText[i]);
	}

}