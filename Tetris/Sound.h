#pragma once

#ifndef SOUND_H
#define SOUND_H

#include "SFML/Audio.hpp"

#include "GamePool.h"

class Sound {

private:

	Sound();
	static Sound* mInstance;

	sf::SoundBuffer mMenuItemUpDownSoundBuffer;
	sf::Sound mMenuItemUpDownSound;
	sf::SoundBuffer mRotateKeySoundBuffer;
	sf::Sound mRotateKeySound;

	sf::Music backGroundMusic;

	const float VOLUME_MENU_ITEMUPDOWN = 100.f;
	const float VOLUME_ROTATEKEY = 40.f;
	const float VOLUME_BACKGROUNDMUSIC = 40.f;

public:

	static Sound* GetInstance() {
		if (mInstance == 0) {
			mInstance = new Sound();
		}
		return mInstance;
	}

	void PlayRotateKeyClicked() { mRotateKeySound.play(); }
	void PlayMenuItemUpDown() { mMenuItemUpDownSound.play(); }

	void PlayBackGroundMusic() { backGroundMusic.play(); }
	void PauseBackGroundMusic() { backGroundMusic.pause(); }
};

#endif