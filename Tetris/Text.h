#pragma once

#include <SFML/Graphics.hpp>

class Text {

private:

	Text();
	sf::Font mFont;

	static Text* mInstance;

	// ����� �ð��� ǥ��
	sf::Text mElapsedTimeText;

	// �÷��̾��� ������ ǥ��
	sf::Text mPlayerScoreText;

	// ������� ����� 
	sf::Text mBackGroundMusicText;

public:

	~Text() {
		mInstance = nullptr;
	}

	static Text* GetInstance() {
		if (mInstance == nullptr) {
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
