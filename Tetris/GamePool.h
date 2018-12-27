#pragma once

#ifndef GAMEPOOL_H
#define GAMEPOOL_H

#include "SFML/Graphics.hpp"

// ※ Sound File
#define FILE_BACKGROUND_MUSIC "sounds/DJ_OKAWARI_Luv_Letter.ogg"
#define FILE_MENUITEM_UPDOWN "sounds/MENU_Up,Down.ogg"
#define FILE_BLOCK_ROTATE_SOUND "sounds/BlockRotateSound.ogg"
#define FILE_BLOCK_DELETE_SOUND "sounds/BlockDeleteSound.ogg"
#define FILE_BLOCK_MOVE_SOUND "sounds/BlockDownSound.ogg"

// ※ Size of Window
#define WINDOW_SIZE_X (1400)
#define WINDOW_SIZE_Y (950)
#define GAME_TITLE "Tetris (beta)"

// ※ Font File
#define FILE_STARTMENU_FONT "fonts/godoMaum.ttf" 
#define FILE_STARTMENU_TITLE_FONT "fonts/tvNBold.ttf"

// ※ Score Record File
#define FILE_RANKING_DATA "Ranking.csv" 

// 전역변수
const size_t ROW_PIXEL_NUMBER = 12;
const size_t COLUMN_PIXEL_NUMBER = 22;

const size_t ONE_BLOCK_PIXEL = 39;
const size_t ROW_PIXEL = ONE_BLOCK_PIXEL * ROW_PIXEL_NUMBER; // 468
const size_t COLUMN_PIXEL = ONE_BLOCK_PIXEL * COLUMN_PIXEL_NUMBER; // 858

const static int BLOCK_NUMBER = (ROW_PIXEL_NUMBER * COLUMN_PIXEL_NUMBER);

const unsigned int BACKGROUND_POSITIONX = 50;
const unsigned int BACKGROUND_POSITIONY = 30;

const size_t BLOCK_COLOR_NUMBER = 7;
const size_t BLOCK_SHAPE_NUMBER = 7;

const sf::Vector2f BlockGeneratePoint =
{ BACKGROUND_POSITIONX + (ONE_BLOCK_PIXEL * (ROW_PIXEL_NUMBER / 2)), BACKGROUND_POSITIONY + ONE_BLOCK_PIXEL * 1 };

const int DEFAULT_BLOCK_MOVINGTIME = 0.5 * 1000;
const int FAST_BLOCK_MOVINGTIME = 0.005 * 1000;

// 전역 Enum
enum eBlockColor {
	Red = 0,
	Skyblue = 1,
	Yellow = 2,
	Purple = 3,
	Orange = 4,
	Green = 5,
	Blue = 6
};

class GamePool {

private:

	GamePool();
	static GamePool* mInstance;

	sf::Sprite mBlockColorSprite[BLOCK_COLOR_NUMBER];
	sf::Texture mBlockColorTexture[BLOCK_COLOR_NUMBER];

public:

	static GamePool* GetInstance() {
		if (mInstance == 0) {
			mInstance = new GamePool();
		}
		return mInstance;
	}

	const sf::Sprite GetBlockColorSprite(const eBlockColor color) { return mBlockColorSprite[color]; };

};

#endif