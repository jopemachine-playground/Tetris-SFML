#include "pch.h"

#include "Sound.h"

Sound* Sound::instance = nullptr;

Sound::Sound() {

	mMenuItemUpDownSoundBuffer.loadFromFile(FILE_MENUITEM_UPDOWN);
	mMenuItemUpDownSound.setBuffer(mMenuItemUpDownSoundBuffer);
	mMenuItemUpDownSound.setVolume(VOLUME_MENU_ITEMUPDOWN);

	mRotateKeySoundBuffer.loadFromFile(FILE_MENUITEM_UPDOWN);
	mRotateKeySound.setBuffer(mRotateKeySoundBuffer);
	mRotateKeySound.setVolume(VOLUME_ROTATEKEY);

	backGroundMusic.openFromFile(FILE_BACKGROUND_MUSIC);
	backGroundMusic.setVolume(VOLUME_BACKGROUNDMUSIC);
	backGroundMusic.setLoop(true);

}
