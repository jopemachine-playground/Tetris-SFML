#pragma once

#include <SFML/Graphics.hpp>

// ※ Sound File
#define FILE_BACKGROUND_MUSIC "sounds/DJ_OKAWARI_Luv_Letter.ogg"
#define FILE_MENUITEM_UPDOWN "sounds/MENU_Up,Down.ogg"
#define FILE_BLOCK_ROTATE_SOUND "sounds/BlockRotateSound.ogg"
#define FILE_BLOCK_DELETE_SOUND "sounds/BlockDeleteSound.ogg"
#define FILE_BLOCK_MOVE_SOUND "sounds/BlockDownSound.ogg"
#define FILE_BLOCK_DOWN_SOUND "sounds/BlockDown.ogg"
#define FILE_BLOCK_DOWNFASTER_SOUND "sounds/BlockDownFaster.ogg"

// ※ Size of Window
#define WINDOW_SIZE_X (1000)
#define WINDOW_SIZE_Y (950)
#define GAME_TITLE "Tetris (beta)"

// ※ Font File
#define FILE_STARTMENU_FONT "fonts/godoMaum.ttf" 
#define FILE_STARTMENU_TITLE_FONT "fonts/tvNBold.ttf"

// ※ Score Record File
#define FILE_RANKING_DATA "Ranking.csv" 

// 디버깅 모드
// #define DEBUG_CONSOLE

// 전역변수

enum eBlockInfo
{
	ROW_PIXEL_NUMBER = 12,
	COLUMN_PIXEL_NUMBER = 23,
	BLOCK_NUMBER = (ROW_PIXEL_NUMBER * COLUMN_PIXEL_NUMBER)
};

enum ePixelNumberInfo
{
	ONE_BLOCK_PIXEL = 39,
	ROW_PIXEL = ONE_BLOCK_PIXEL * ROW_PIXEL_NUMBER,
	COLUMN_PIXEL = ONE_BLOCK_PIXEL * COLUMN_PIXEL_NUMBER,
	BACKGROUND_POSITIONX = 50,
	BACKGROUND_POSITIONY = 30
};

constexpr float DEFAULT_BLOCK_MOVINGTIME = 0.797;
constexpr float FAST_BLOCK_MOVINGTIME = 0.05;

constexpr size_t MAX_UNITBLOCK_NUMBER = 4;

const sf::Vector2f BlockGeneratePoint =
{ BACKGROUND_POSITIONX + (ONE_BLOCK_PIXEL * (ROW_PIXEL_NUMBER / 2)),
static_cast<int> (BACKGROUND_POSITIONY) + ONE_BLOCK_PIXEL };

const sf::Vector2f NextBlockPoint = { 650, 130 };


// 전역 Enum
enum eBlockColor 
{
	Red = 0,
	Skyblue = 1,
	Yellow = 2,
	Purple = 3,
	Orange = 4,
	Green = 5,
	Blue = 6,
	Default = 7,
	BLOCK_COLOR_NUMBER
};

enum eBlockShape
{
	I = 0,
	Z = 1,
	S = 2,
	T = 3,
	L = 4,
	J = 5,
	O = 6,
	BLOCK_SHAPE_NUMBER
};

class GamePool 
{

private:

	GamePool();
	static GamePool* mInstance;

	sf::Sprite mBlockColorSprite[BLOCK_COLOR_NUMBER];
	sf::Texture mBlockColorTexture[BLOCK_COLOR_NUMBER];

	sf::Texture mBlockTransparentTexture;
	sf::Sprite mBlockTransparentSprite;


public:

	static GamePool* GetInstance() 
	{
		if (mInstance == nullptr) {
			mInstance = new GamePool();
		}
		return mInstance;
	}

	const sf::Sprite GetBlockColorSprite(const eBlockColor& color) const { return mBlockColorSprite[color]; };

	const sf::Sprite GetBlockTransparentSprite() const { return mBlockTransparentSprite; }


};
