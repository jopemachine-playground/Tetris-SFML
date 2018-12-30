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
	
	static Image* mInstance;

public:

	static Image* GetInstance()
	{
		if (mInstance == 0)
		{
			mInstance = new Image();
		}
		return mInstance;
	}

	const sf::Sprite GetSprite() { return mSelectedPictureSprite; }

	const unsigned int GetSelectedNumber() { return mSelectedNumber; }

	const sf::Sprite GetExcellentSprite() { return mExcellentSprite; }

	const sf::Sprite GetGoodjobSprite() { return mGoodjobSprite; }
};