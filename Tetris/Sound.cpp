#include "pch.h"

#include <cassert>
#include <random>
#include <iostream>
#include "Sound.h"

Sound* Sound::mInstance = nullptr;

Sound::Sound()
{

	if (!mMenuItemUpDownSoundBuffer.loadFromFile(FILE_MENUITEM_UPDOWN))
	{
		std::cerr << "ERROR - File Not found : " << FILE_MENUITEM_UPDOWN << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_MENUITEM_UPDOWN);
	}
	mMenuItemUpDownSound.setBuffer(mMenuItemUpDownSoundBuffer);
	mMenuItemUpDownSound.setVolume(VOLUME_MENU_ITEMUPDOWN);

	if (!mRotateKeySoundBuffer.loadFromFile(FILE_BLOCK_ROTATE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_ROTATE_SOUND << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_BLOCK_ROTATE_SOUND);
	}
	mRotateKeySound.setBuffer(mRotateKeySoundBuffer);
	mRotateKeySound.setVolume(VOLUME_ROTATEKEY);

	if (!mBlockMoveSoundBuffer.loadFromFile(FILE_BLOCK_MOVE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_MOVE_SOUND << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_BLOCK_MOVE_SOUND);
	}
	mBlockMoveSound.setBuffer(mBlockMoveSoundBuffer);
	mBlockMoveSound.setVolume(VOLUME_BLOCK_MOVE);

	if (!mBlockMoveDeleteSoundBuffer.loadFromFile(FILE_BLOCK_DELETE_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_DELETE_SOUND << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_BLOCK_DELETE_SOUND);
	}
	mBlockMoveDeleteSound.setBuffer(mBlockMoveDeleteSoundBuffer);
	mBlockMoveDeleteSound.setVolume(VOLUME_BLOCK_DELETE);

	if (!mBlockDownFasterSoundBuffer.loadFromFile(FILE_BLOCK_DOWNFASTER_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_DOWNFASTER_SOUND << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_BLOCK_DOWNFASTER_SOUND);
	}
	mBlockDownFasterSound.setBuffer(mBlockDownFasterSoundBuffer);

	if (!mBlockDownSoundBuffer.loadFromFile(FILE_BLOCK_DOWN_SOUND))
	{
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_DOWN_SOUND << std::endl;
		assert(false, "ERROR - File Not found : " << FILE_BLOCK_DOWN_SOUND);
	}
	mBlockDownSound.setBuffer(mBlockDownSoundBuffer);


	// ·£´ýÀ¸·Î ¹è°æÀ½¾Ç °áÁ¤
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, BACKGROUND_MUSIC_NUMBER - 1);

	mSelectedMusicNumber = static_cast<eBackGroundMusicFile> (dist(gen));
	mSelectedMusicName = MusicFileGetString(mSelectedMusicNumber);

	backGroundMusic.openFromFile("sounds/" + mSelectedMusicName + ".ogg");
	backGroundMusic.setVolume(VOLUME_BACKGROUNDMUSIC);
	backGroundMusic.setLoop(true);

}

std::string Sound::MusicFileGetString(eBackGroundMusicFile bgm) 
{

	switch (bgm) 
	{
	case acousticbreeze: { return "acousticbreeze"; break; }
	case anewbeginning: { return "anewbeginning"; break; }
	case cute: { return "cute"; break; }
	case hey: { return "hey"; break; }
	case littleidea: { return "littleidea"; break; }
	}

} 
