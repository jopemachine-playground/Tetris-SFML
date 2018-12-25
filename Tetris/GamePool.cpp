#include "pch.h"

#include "GamePool.h"

GamePool* GamePool::mInstance = nullptr;

GamePool::GamePool() {

	// 각 색깔 블록들의 이미지 파일을 로드

	mBlockColorTexture[Red].loadFromFile("images/red.png");
	mBlockColorTexture[Skyblue].loadFromFile("images/skyblue.png");
	mBlockColorTexture[Yellow].loadFromFile("images/yellow.png");
	mBlockColorTexture[Purple].loadFromFile("images/purple.png");
	mBlockColorTexture[Orange].loadFromFile("images/orange.png");
	mBlockColorTexture[Green].loadFromFile("images/green.png");
	mBlockColorTexture[Blue].loadFromFile("images/blue.png");

	mBlockColorSprite[1].setTexture(mBlockColorTexture[Red]);
	mBlockColorSprite[2].setTexture(mBlockColorTexture[Skyblue]);
	mBlockColorSprite[3].setTexture(mBlockColorTexture[Yellow]);
	mBlockColorSprite[4].setTexture(mBlockColorTexture[Purple]);
	mBlockColorSprite[5].setTexture(mBlockColorTexture[Orange]);
	mBlockColorSprite[6].setTexture(mBlockColorTexture[Green]);
	mBlockColorSprite[7].setTexture(mBlockColorTexture[Blue]);

}
