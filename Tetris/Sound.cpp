#include "pch.h"

#include <random>
#include <iostream>
#include "Sound.h"

Sound* Sound::mInstance = nullptr;

Sound::Sound()
{

	if (!mMenuItemUpDownSoundBuffer.loadFromFile(FILE_MENUITEM_UPDOWN))
	{
		std::cerr << "ERROR - File Not found : " << FILE_MENUITEM_UPDOWN << std::endl;
	}
	mMenuItemUpDownSound.setBuffer(mMenuItemUpDownSoundBuffer);
	mMenuItemUpDownSound.setVolume(VOLUME_MENU_ITEMUPDOWN);

	if (!mRotateKeySoundBuffer.loadFromFile(FILE_BLOCK_ROTATE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_ROTATE_SOUND << std::endl;
	}
	mRotateKeySound.setBuffer(mRotateKeySoundBuffer);
	mRotateKeySound.setVolume(VOLUME_ROTATEKEY);

	if (!mBlockMoveSoundBuffer.loadFromFile(FILE_BLOCK_MOVE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_MOVE_SOUND << std::endl;
	}
	mBlockMoveSound.setBuffer(mBlockMoveSoundBuffer);

	if (!mBlockMoveDeleteSoundBuffer.loadFromFile(FILE_BLOCK_DELETE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_DELETE_SOUND << std::endl;
	}
	mBlockMoveDeleteSound.setBuffer(mBlockMoveDeleteSoundBuffer);


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, BACKGROUND_MUSIC_NUMBER - 1);

	mSelectedMusicNumber = static_cast<eBackGroundMusicFile> (dist(gen));
	mSelectedMusicName = MusicFileGetString(mSelectedMusicNumber);

	backGroundMusic.openFromFile("sounds/" + mSelectedMusicName + ".ogg");
	backGroundMusic.setVolume(VOLUME_BACKGROUNDMUSIC);
	backGroundMusic.setLoop(true);

}

std::string Sound::MusicFileGetString(eBackGroundMusicFile bgm) {

	switch (bgm) {
	case DJ_Okawari_Flower_Dance: { return "DJ_Okawari_Flower_Dance"; break; }
	case DJ_OKAWARI_Luv_Letter: { return "DJ_OKAWARI_Luv_Letter"; break; }
	case DJ_Okawari_Perfect_Blue: { return "DJ_Okawari_Perfect_Blue"; break; }
	case Dj_Okawari_Voice_of_Nature: { return "Dj_Okawari_Voice_of_Nature"; break; }
	case Sereno: { return "Sereno"; break; }
	}

}
