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
	sf::Text mCongratulationText;

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

	void DrawTextWhileGame(sf::RenderWindow& window);

	void DrawTextAfterGame(sf::RenderWindow& window);

	void UpdateScore();

	void UpdateElapsedTime(int elapsedTimeWhilePlaying);

	void SetCongratulationText();
};
