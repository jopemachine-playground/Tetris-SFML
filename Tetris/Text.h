#pragma once

#include "SFML/Graphics.hpp"

class Text {

private:
	Text();
	sf::Font mFont;

	static Text* mInstance;

public:

	static Text* getInstance() {
		if (mInstance == 0) {
			mInstance = new Text();
		}
		return mInstance;
	}


};
