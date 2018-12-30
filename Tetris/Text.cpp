#include "pch.h"

#include "Sound.h"
#include "Text.h"
#include "Ranking.h"

#include <iostream>

Text* Text::mInstance = nullptr;

// ���� : Sound �ʱ�ȭ �� Text�� �ʱ�ȭ �ؾ� ��.

Text::Text() 
{
	Sound* sc = Sound::GetInstance();
	Ranking *rk = Ranking::GetInstance();

	mFont.loadFromFile("fonts/HS_Summer.ttf");

	mPlayerScoreText.setFont(mFont);
	mPlayerScoreText.setPosition(900, 600);
	mPlayerScoreText.setString(L"���� : " + std::to_wstring(rk->GetPlayerScore()) + L" ��");
	mPlayerScoreText.setFillColor(sf::Color::Black);

	mElapsedTimeText.setFont(mFont);
	mElapsedTimeText.setPosition(900, 700);
	mElapsedTimeText.setFillColor(sf::Color::Black);
	mElapsedTimeText.setString(L"�� ��");

	mBackGroundMusicText.setFont(mFont);
	mBackGroundMusicText.setPosition(900, 800);
	mBackGroundMusicText.setFillColor(sf::Color::Black);
	mBackGroundMusicText.setString(sc->GetSelectedMusicName());

}