#include "pch.h"

#include <iostream>

#include "GamePool.h"

GamePool* GamePool::mInstance = nullptr;

GamePool::GamePool() 
{

	// 각 색깔 블록들의 이미지 파일을 로드

	if (!mBlockColorTexture[Red].loadFromFile("images/red.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/red.png" << std::endl;
	}

	if (!mBlockColorTexture[Skyblue].loadFromFile("images/skyblue.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/skyblue.png" << std::endl;
	}

	if (!mBlockColorTexture[Yellow].loadFromFile("images/yellow.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/yellow.png" << std::endl;
	}

	if (!mBlockColorTexture[Purple].loadFromFile("images/purple.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/purple.png" << std::endl;
	}

	if (!mBlockColorTexture[Orange].loadFromFile("images/orange.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/orange.png" << std::endl;
	}

	if (!mBlockColorTexture[Green].loadFromFile("images/green.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/green.png" << std::endl;
	}

	if (!mBlockColorTexture[Blue].loadFromFile("images/blue.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/blue.png" << std::endl;
	}

	if (!mBlockColorTexture[Default].loadFromFile("images/default.png"))
	{
		std::cerr << "ERROR - File Not found : " << "images/default.png" << std::endl;
	}

	mBlockColorSprite[Red].setTexture(mBlockColorTexture[Red]);
	mBlockColorSprite[Skyblue].setTexture(mBlockColorTexture[Skyblue]);
	mBlockColorSprite[Yellow].setTexture(mBlockColorTexture[Yellow]);
	mBlockColorSprite[Purple].setTexture(mBlockColorTexture[Purple]);
	mBlockColorSprite[Orange].setTexture(mBlockColorTexture[Orange]);
	mBlockColorSprite[Green].setTexture(mBlockColorTexture[Green]);
	mBlockColorSprite[Blue].setTexture(mBlockColorTexture[Blue]);
	mBlockColorSprite[Default].setTexture(mBlockColorTexture[Default]);

}

