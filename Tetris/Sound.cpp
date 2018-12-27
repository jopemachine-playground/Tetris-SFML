#include "pch.h"

#include <iostream>
#include "Sound.h"

Sound* Sound::mInstance = nullptr;

Sound::Sound() {

	if (!mMenuItemUpDownSoundBuffer.loadFromFile(FILE_MENUITEM_UPDOWN)) 
		std::cerr << "ERROR - File Not found : " << FILE_MENUITEM_UPDOWN << std::endl;
	mMenuItemUpDownSound.setBuffer(mMenuItemUpDownSoundBuffer);
	mMenuItemUpDownSound.setVolume(VOLUME_MENU_ITEMUPDOWN);

	if (!mRotateKeySoundBuffer.loadFromFile(FILE_BLOCK_ROTATE_SOUND))
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_ROTATE_SOUND << std::endl;
	mRotateKeySound.setBuffer(mRotateKeySoundBuffer);
	mRotateKeySound.setVolume(VOLUME_ROTATEKEY);

	if (!mBlockMoveSoundBuffer.loadFromFile(FILE_BLOCK_MOVE_SOUND))
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_MOVE_SOUND << std::endl;
	mBlockMoveSound.setBuffer(mBlockMoveSoundBuffer);

	if (!mBlockMoveDeleteSoundBuffer.loadFromFile(FILE_BLOCK_DELETE_SOUND))
		std::cerr << "ERROR - File Not found : " << FILE_BLOCK_DELETE_SOUND << std::endl;
	mBlockMoveDeleteSound.setBuffer(mBlockMoveDeleteSoundBuffer);

	if (!backGroundMusic.openFromFile(FILE_BACKGROUND_MUSIC))
		std::cerr << "ERROR - File Not found : " << FILE_BACKGROUND_MUSIC << std::endl;
	backGroundMusic.setVolume(VOLUME_BACKGROUNDMUSIC);
	backGroundMusic.setLoop(true);

}
