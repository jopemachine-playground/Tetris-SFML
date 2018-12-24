#include "pch.h"

#include "SFML/Graphics.hpp"

#include "Picture.h"

#include <random>
// 헤더파일의 인클루드 순서에 주의할 것.

Picture::Picture() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	std::uniform_int_distribution<> dist(1, PICTURE_NUMBER);
	
	unsigned int mSelectedPictureNumber = dist(gen);


	mSelectedPictureTexture.loadFromFile("images/Picture" + std::to_string(mSelectedPictureNumber) + ".png");
	mSelectedPictureSprite.setTexture(mSelectedPictureTexture);

}



