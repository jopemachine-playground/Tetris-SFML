#pragma once

#include <SFML/Graphics.hpp>

class Text {

private:

	Text();
	sf::Font mFont;

	static Text* mInstance;

	// ���� �� ǥ���� ����
	sf::Text mElapsedTimeText;
	sf::Text mPlayerScoreText;
	sf::Text mBackGroundMusicText;

	// ������ ���� �� ǥ���� ����
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
