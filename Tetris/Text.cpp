#include "pch.h"

#include "Sound.h"
#include "Text.h"
#include "Ranking.h"

#include <iostream>

Text* Text::mInstance = nullptr;

// 주의 : Sound 초기화 후 Text를 초기화 해야 함.

Text::Text() 
{
	Sound* sc = Sound::GetInstance();
	Ranking *rk = Ranking::GetInstance();

	mFont.loadFromFile("fonts/HS_Summer.ttf");

	mPlayerScoreText.setFont(mFont);
	mPlayerScoreText.setPosition(900, 600);
	mPlayerScoreText.setString(L"점수 : " + std::to_wstring(rk->GetPlayerScore()) + L" 점");
	mPlayerScoreText.setFillColor(sf::Color::Black);

	mElapsedTimeText.setFont(mFont);
	mElapsedTimeText.setPosition(900, 700);
	mElapsedTimeText.setFillColor(sf::Color::Black);
	mElapsedTimeText.setString(L"분 초");

	mBackGroundMusicText.setFont(mFont);
	mBackGroundMusicText.setPosition(900, 800);
	mBackGroundMusicText.setFillColor(sf::Color::Black);
	mBackGroundMusicText.setString(sc->GetSelectedMusicName());

}