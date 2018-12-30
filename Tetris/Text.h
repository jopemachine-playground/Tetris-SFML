#pragma once

#include <SFML/Graphics.hpp>

class Text {

private:

	Text();
	sf::Font mFont;

	static Text* mInstance;

	// 게임 중 표시할 정보
	sf::Text mElapsedTimeText;
	sf::Text mPlayerScoreText;
	sf::Text mBackGroundMusicText;

	// 게임이 끝난 후 표시할 정보
	sf::Text mPlayerScoreResultText;
	sf::Text mElapsedTimeResultText;
	sf::Text mGameEndText;

public:

	~Text()
	{
		mInstance = nullptr;
	}

	static Text* GetInstance() 
	{
		if (mInstance == nullptr)
		{
			mInstance = new Text();
		}
		return mInstance;
	}

	void DrawTextWhileGame (sf::RenderWindow& window)
	{
		window.draw(mElapsedTimeText);
		window.draw(mPlayerScoreText);
		window.draw(mBackGroundMusicText);
	}

	void DrawTextAfterGame(sf::RenderWindow& window)
	{
		window.draw(mPlayerScoreResultText);
		window.draw(mElapsedTimeResultText);
		window.draw(mGameEndText);
	}

	void UpdateScore();

	void UpdateElapsedTime(int elapsedTimeWhilePlaying);

};
