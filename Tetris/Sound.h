#pragma once

#include <SFML/Audio.hpp>

#include "GamePool.h"

class Sound
{

private:

	Sound();

	static Sound* mInstance;

	const static int BACKGROUND_MUSIC_NUMBER = 5;

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

	// 블록 빠르게 내리기, 한 번에 내리기
	sf::SoundBuffer mBlockDownFasterSoundBuffer;
	sf::Sound mBlockDownFasterSound;
	sf::SoundBuffer mBlockDownSoundBuffer;
	sf::Sound mBlockDownSound;

	// 배경음
	sf::Music backGroundMusic;

	const float VOLUME_MENU_ITEMUPDOWN = 100.f;
	const float VOLUME_BLOCK_MOVE = 40.f;
	const float VOLUME_BLOCK_DELETE = 50.f;
	const float VOLUME_ROTATEKEY = 100.f;
	const float VOLUME_BACKGROUNDMUSIC = 40.f;

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

	inline void PlayRotateKeyClicked() { mRotateKeySound.play(); }
	inline void PlayMenuItemUpDown() { mMenuItemUpDownSound.play(); }

	inline void PlayBlockMove() { mBlockMoveSound.play(); }
	inline void PlayBlockDelete() { mBlockMoveDeleteSound.play(); }

	inline void PlayBackGroundMusic() { backGroundMusic.play(); }
	inline void PauseBackGroundMusic() { backGroundMusic.pause(); }

	inline void PlayBlockDown() { mBlockDownSound.play(); }
	inline void PlayBlockDownFaster() { mBlockDownFasterSound.play(); }

	std::string MusicFileGetString(eBackGroundMusicFile bgm);
	std::string GetSelectedMusicName() const { return mSelectedMusicName; }

};
