#include "pch.h"

#include "Text.h"
#include "Ranking.h"

Text* Text::mInstance = nullptr;

Text::Text() {

	Ranking *rk = Ranking::GetInstance();

	mFont.loadFromFile("fonts/HS_Summer.ttf");

	mPlayerScoreText.setFont(mFont);
	mPlayerScoreText.setPosition(900, 600);
	mPlayerScoreText.setString(std::to_wstring(rk->GetPlayerScore()) + L" ��");
	mPlayerScoreText.setFillColor(sf::Color::Black);

	mElapsedTimeText.setFont(mFont);
	mElapsedTimeText.setPosition(900, 700);
	mElapsedTimeText.setFillColor(sf::Color::Black);
	mElapsedTimeText.setString(L"�� ��");

	mBackGroundMusicText.setFont(mFont);
	mBackGroundMusicText.setPosition(500, 800);
	mBackGroundMusicText.setFillColor(sf::Color::Black);
	mBackGroundMusicText.setString(L"������� : DJ_OKAWARI_Luv_Letter");
}