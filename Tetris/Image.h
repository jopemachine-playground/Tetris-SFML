#pragma once

#include <SFML/Graphics.hpp>

#include "GamePool.h"

class Image
{

private:

	Image();
	const unsigned int BACKGROUND_PICTURE_NUMBER = 10;

	sf::Texture mSelectedPictureTexture;
	sf::Sprite mSelectedPictureSprite;
	unsigned int mSelectedNumber;
	
	sf::Texture mExcellentTexture;
	sf::Sprite mExcellentSprite;
	sf::Texture mGoodjobTexture;
	sf::Sprite mGoodjobSprite;

	sf::Texture mNextBlockPanelTexture;
	sf::Sprite mNextBlockPanelSprite;

	static Image* mInstance;

public:

	~Image()
	{
		mInstance = nullptr;
	}

	static Image* GetInstance()
	{
		if (mInstance == 0)
		{
			mInstance = new Image();
		}
		return mInstance;
	}

	const unsigned int GetSelectedNumber() { return mSelectedNumber; }

	const sf::Sprite GetExcellentSprite() { return mExcellentSprite; }

	const sf::Sprite GetGoodjobSprite() { return mGoodjobSprite; }

	void DrawBackGround(sf::RenderWindow& window) 
	{ 
		window.draw(mSelectedPictureSprite);
	};

	void DrawNextBlockPanel(sf::RenderWindow& window) 
	{
		window.draw(mNextBlockPanelSprite);
	}


};