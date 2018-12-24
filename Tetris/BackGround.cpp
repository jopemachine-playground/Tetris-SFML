#include "pch.h"

#include "BackGround.h"

BackGround::BackGround() {
	
	mTexture.loadFromFile("images/BackGround.png");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(BACKGROUND_POSITIONX, BACKGROUND_POSITIONY);

}
