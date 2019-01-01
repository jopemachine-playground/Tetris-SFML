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

// ���� : Sound �ʱ�ȭ �� Text�� �ʱ�ȭ �ؾ� ��.

Text::Text() 
{
	Sound* sc = Sound::GetInstance();
	Ranking *rk = Ranking::GetInstance();

	mFont.loadFromFile("fonts/HS_Summer.ttf");

	// ���� �� ǥ�õǴ� ����
	mPlayerScoreText.setFont(mFont);
	mPlayerScoreText.setPosition(500, 600);
	mPlayerScoreText.setString(L"���� : 0 ��");
	mPlayerScoreText.setFillColor(sf::Color::Black);

	mElapsedTimeText.setFont(mFont);
	mElapsedTimeText.setPosition(500, 700);
	mElapsedTimeText.setFillColor(sf::Color::Black);
	mElapsedTimeText.setString(L"��� �ð� : 0�� 0��");

	mBackGroundMusicText.setFont(mFont);
	mBackGroundMusicText.setPosition(500, 800);
	mBackGroundMusicText.setFillColor(sf::Color::Black);

	// string�� wstring���� ��ȯ�ϱ� ���� ��ũ�� ���
	USES_CONVERSION;
	std::wstring MusicName = A2W(sc->GetSelectedMusicName().c_str());
	mBackGroundMusicText.setString(L"��� ����: " + MusicName);

	// ������ ���� �� ǥ�õǴ� ����
	mPlayerScoreResultText.setFont(mFont);
	mPlayerScoreResultText.setPosition(500, 750);
	mPlayerScoreResultText.setString(L"���� : 0 ��");
	mPlayerScoreResultText.setFillColor(sf::Color::Black);

	mElapsedTimeResultText.setFont(mFont);
	mElapsedTimeResultText.setPosition(500, 810);
	mElapsedTimeResultText.setString(L"���  �ð� : 0�� 0��");
	mElapsedTimeResultText.setFillColor(sf::Color::Black);

	mGameEndText.setFont(mFont);
	mGameEndText.setCharacterSize(50);
	mGameEndText.setPosition(500, 400);
	mGameEndText.setString(L"����  ����!\n\n Thanks For Playing ��");
	mGameEndText.setFillColor(sf::Color::Black);

	mCongratulationText.setFont(mFont);
	mCongratulationText.setPosition(500, 200);
	mCongratulationText.setString("");
	mCongratulationText.setFillColor(sf::Color::Black);
}

void Text::UpdateScore()
{
	Ranking* rk = Ranking::GetInstance();

	mPlayerScoreText.setString(L"���� : " + std::to_wstring(rk->GetPlayerScore()) + L" ��");
	mPlayerScoreResultText.setString(L"����  ���� : " + std::to_wstring(rk->GetPlayerScore()) + L" ��");
}

void Text::UpdateElapsedTime(int elapsedTimeWhilePlaying)
{
	Ranking* rk = Ranking::GetInstance();

	unsigned int elapsedMinute = elapsedTimeWhilePlaying / 60;
	unsigned int elapsedSecond = elapsedTimeWhilePlaying % 60;

	mElapsedTimeText.setString
	(L"��� �ð� : " + std::to_wstring(elapsedMinute) + L"�� "
		+ std::to_wstring(elapsedSecond) + L"��");

	mElapsedTimeResultText.setString
	(L"��� �ð� : " + std::to_wstring(elapsedMinute) + L"�� "
		+ std::to_wstring(elapsedSecond) + L"��");
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
	mCongratulationText.setString(L"�����մϴ�! �ְ� ����� ����߽��ϴ�!");
	mPlayerScoreResultText.setFillColor(sf::Color::Red);
}



