#pragma once

#include "SFML/Graphics.hpp"

class Text {

private:

	Text();
	sf::Font mFont;

	static Text* mInstance;

	// 경과된 시간을 표시
	sf::Text mElapsedTimeText;

	// 플레이어의 점수를 표시
	sf::Text mPlayerScoreText;

	// 재생중인 배경음 
	sf::Text mBackGroundMusicText;

public:

	static Text* GetInstance() {
		if (mInstance == 0) {
			mInstance = new Text();
		}
		return mInstance;
	}

	void DrawText(sf::RenderWindow& window) {
		window.draw(mElapsedTimeText);
		window.draw(mPlayerScoreText);
		window.draw(mBackGroundMusicText);
	}


};
