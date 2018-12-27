#pragma once

#ifndef SOUND_H
#define SOUND_H

#include "SFML/Audio.hpp"

#include "GamePool.h"

class Sound {

private:

	Sound();
	static Sound* mInstance;

	// 메뉴 이동
	sf::SoundBuffer mMenuItemUpDownSoundBuffer;
	sf::Sound mMenuItemUpDownSound;

	// 블록 회전, 이동, 삭제
	sf::SoundBuffer mRotateKeySoundBuffer;
	sf::Sound mRotateKeySound;
	sf::SoundBuffer mBlockMoveSoundBuffer;
	sf::Sound mBlockMoveSound;
	sf::SoundBuffer mBlockMoveDeleteSoundBuffer;
	sf::Sound mBlockMoveDeleteSound;

	// 배경음
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

	void PlayBlockMove() { mBlockMoveSound.play(); }
	void PlayBlockDelete() { mBlockMoveDeleteSound.play(); }

	void PlayBackGroundMusic() { backGroundMusic.play(); }
	void PauseBackGroundMusic() { backGroundMusic.pause(); }
};

#endif