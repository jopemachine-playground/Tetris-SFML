#pragma once

#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>

#include "GamePool.h"

class Sound
{

private:

	Sound();

	static Sound* mInstance;

	const static int BACKGROUND_MUSIC_NUMBER = 5;

	// �޴� �̵�
	sf::SoundBuffer mMenuItemUpDownSoundBuffer;
	sf::Sound mMenuItemUpDownSound;

	// ��� ȸ��, �̵�, ����
	sf::SoundBuffer mRotateKeySoundBuffer;
	sf::Sound mRotateKeySound;
	sf::SoundBuffer mBlockMoveSoundBuffer;
	sf::Sound mBlockMoveSound;
	sf::SoundBuffer mBlockMoveDeleteSoundBuffer;
	sf::Sound mBlockMoveDeleteSound;

	// ��� ������ ������, �� ���� ������
	sf::SoundBuffer mBlockDownFasterSoundBuffer;
	sf::Sound mBlockDownFasterSound;
	sf::SoundBuffer mBlockDownSoundBuffer;
	sf::Sound mBlockDownSound;

	// �����
	sf::Music backGroundMusic;

	const float VOLUME_MENU_ITEMUPDOWN = 100.f;
	const float VOLUME_BLOCK_MOVE = 40.f;
	const float VOLUME_BLOCK_DELETE = 50.f;
	const float VOLUME_ROTATEKEY = 100.f;
	const float VOLUME_BACKGROUNDMUSIC = 40;

	enum eBackGroundMusicFile {
		DJ_Okawari_Flower_Dance = 0,
		DJ_OKAWARI_Luv_Letter = 1,
		DJ_Okawari_Perfect_Blue = 2,
		Dj_Okawari_Voice_of_Nature = 3,
		Sereno = 4
	};

	eBackGroundMusicFile mSelectedMusicNumber;
	std::string mSelectedMusicName;

public:

	~Sound()
	{
		mInstance = nullptr;
	}

	static Sound* GetInstance()
	{
		if (mInstance == nullptr)
		{
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

	void PlayBlockDown() { mBlockDownSound.play(); }
	void PlayBlockDownFaster() { mBlockDownFasterSound.play(); }

	std::string MusicFileGetString(eBackGroundMusicFile bgm);
	std::string GetSelectedMusicName() const { return mSelectedMusicName; }

};

#endif