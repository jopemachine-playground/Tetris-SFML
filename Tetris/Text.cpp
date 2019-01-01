#include "pch.h"

#include "Sound.h"
#include "Text.h"
#include "Ranking.h"

#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>

#include <iostream>

Text* Text::mInstance = nullptr;

// 주의 : Sound 초기화 후 Text를 초기화 해야 함.

Text::Text() 
{
	Sound* sc = Sound::GetInstance();
	Ranking *rk = Ranking::GetInstance();

	mFont.loadFromFile("fonts/HS_Summer.ttf");

	// 게임 중 표시되는 정보
	mPlayerScoreText.setFont(mFont);
	mPlayerScoreText.setPosition(500, 600);
	mPlayerScoreText.setString(L"점수 : 0 점");
	mPlayerScoreText.setFillColor(sf::Color::Black);

	mElapsedTimeText.setFont(mFont);
	mElapsedTimeText.setPosition(500, 700);
	mElapsedTimeText.setFillColor(sf::Color::Black);
	mElapsedTimeText.setString(L"경과 시간 : 0분 0초");

	mBackGroundMusicText.setFont(mFont);
	mBackGroundMusicText.setPosition(500, 800);
	mBackGroundMusicText.setFillColor(sf::Color::Black);

	// string을 wstring으로 변환하기 위한 매크로 사용
	USES_CONVERSION;
	std::wstring MusicName = A2W(sc->GetSelectedMusicName().c_str());
	mBackGroundMusicText.setString(L"배경 음악: " + MusicName);

	// 게임이 끝난 후 표시되는 정보
	mPlayerScoreResultText.setFont(mFont);
	mPlayerScoreResultText.setPosition(500, 750);
	mPlayerScoreResultText.setString(L"점수 : 0 점");
	mPlayerScoreResultText.setFillColor(sf::Color::Black);

	mElapsedTimeResultText.setFont(mFont);
	mElapsedTimeResultText.setPosition(500, 810);
	mElapsedTimeResultText.setString(L"경과  시간 : 0분 0초");
	mElapsedTimeResultText.setFillColor(sf::Color::Black);

	mGameEndText.setFont(mFont);
	mGameEndText.setCharacterSize(50);
	mGameEndText.setPosition(500, 400);
	mGameEndText.setString(L"게임  종료!\n\n Thanks For Playing ♥");
	mGameEndText.setFillColor(sf::Color::Black);

	mCongratulationText.setFont(mFont);
	mCongratulationText.setPosition(500, 200);
	mCongratulationText.setString("");
	mCongratulationText.setFillColor(sf::Color::Black);
}

void Text::UpdateScore()
{
	Ranking* rk = Ranking::GetInstance();

	mPlayerScoreText.setString(L"점수 : " + std::to_wstring(rk->GetPlayerScore()) + L" 점");
	mPlayerScoreResultText.setString(L"최종  점수 : " + std::to_wstring(rk->GetPlayerScore()) + L" 점");
}

void Text::UpdateElapsedTime(int elapsedTimeWhilePlaying)
{
	Ranking* rk = Ranking::GetInstance();

	unsigned int elapsedMinute = elapsedTimeWhilePlaying / 60;
	unsigned int elapsedSecond = elapsedTimeWhilePlaying % 60;

	mElapsedTimeText.setString
	(L"경과 시간 : " + std::to_wstring(elapsedMinute) + L"분 "
		+ std::to_wstring(elapsedSecond) + L"초");

	mElapsedTimeResultText.setString
	(L"경과 시간 : " + std::to_wstring(elapsedMinute) + L"분 "
		+ std::to_wstring(elapsedSecond) + L"초");
}

void Text::DrawTextWhileGame(sf::RenderWindow& window)
{
	window.draw(mElapsedTimeText);
	window.draw(mPlayerScoreText);
	window.draw(mBackGroundMusicText);
}

void Text::DrawTextAfterGame(sf::RenderWindow& window)
{
	window.draw(mPlayerScoreResultText);
	window.draw(mElapsedTimeResultText);
	window.draw(mGameEndText);
	window.draw(mCongratulationText);
}

void Text::SetCongratulationText()
{
	mCongratulationText.setString(L"축하합니다! 최고 기록을 경신했습니다!");
	mPlayerScoreResultText.setFillColor(sf::Color::Red);
}



