#include "pch.h"

#include <SFML/Graphics.hpp>

#include <time.h>
#include "Image.h"

#include <random>
// 헤더파일의 인클루드 순서에 주의할 것.

Image* Image::mInstance = nullptr;

Image::Image() {

	std::random_device rd;   
	std::mt19937 gen(rd());  
	std::uniform_int_distribution<> dist(1, BACKGROUND_PICTURE_NUMBER);
	
	mSelectedNumber = dist(gen);

	mSelectedPictureTexture.loadFromFile("images/Picture" + std::to_string(mSelectedNumber) + ".png");
	mSelectedPictureSprite.setTexture(mSelectedPictureTexture);

	mExcellentTexture.loadFromFile("images/Excellent.png");
	mExcellentSprite.setPosition(500,500);
	mExcellentSprite.setTexture(mExcellentTexture);

	mGoodjobTexture.loadFromFile("images/Good.png");
	mGoodjobSprite.setPosition(500,500);
	mGoodjobSprite.setTexture(mGoodjobTexture);


}






