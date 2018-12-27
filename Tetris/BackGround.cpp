#include "pch.h"

#include <iostream>
#include "BackGround.h"

BackGround::BackGround() {
	
	if (!mTexture.loadFromFile("images/BackGround.png"))
		std::cerr << "ERROR - File Not found : " << "images/BackGround.png" << std::endl;

	mSprite.setTexture(mTexture);
	mSprite.setPosition(BACKGROUND_POSITIONX, BACKGROUND_POSITIONY);

}
