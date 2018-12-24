#include "pch.h"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <time.h>
#include <Windows.h>
#undef min
#undef max

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
#include "BackGround.h"
#include "Game.h"
#include "Picture.h"
#include "Sound.h"
#include "StartMenu.h"
#include "Text.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

StartMenuPoint:

	sf::RenderWindow startWindow(sf::VideoMode(1000, 667), GAME_TITLE);
	sf::Vector2i MousePosition;
	sf::Event MenuEvent;
	StartMenu startMenu(WINDOW_SIZE_X, WINDOW_SIZE_Y);

	while (startWindow.isOpen())
	{
		while (startWindow.pollEvent(MenuEvent))
		{
			switch (MenuEvent.type)
			{

			case sf::Event::Closed: {

				exit(0);
				break;

			}
			case sf::Event::KeyPressed: {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) startMenu.MoveUp();

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) startMenu.MoveDown();

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

					switch (startMenu.GetSelectedItemIndex()) {

					case StartMenu::BUTTON_PLAY:

						startWindow.close();
						goto GameStartingPoint;
						break;

					case StartMenu::BUTTON_OPTION:

						Sleep(140);
						break;

					case StartMenu::BUTTON_QUIT:
						exit(0);
						break;
					}
				}
			}

			}

			startWindow.clear();
			startMenu.Draw(startWindow);
			startWindow.display();
		}
	}

GameStartingPoint:


	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), GAME_TITLE);
	sf::Event event;

	BackGround* background = new BackGround();
	Picture* picture = new Picture();
	Sound* soundManage = Sound::getInstance();
	soundManage->PlayBackGroundMusic();

	Text *textManage = Text::getInstance();

	srand(time(0));

	int dx = 0;
	bool rotate = 0;
	int colorNum = 1;
	float timer = 0, delay = 0.3;

	sf::Clock clock;

GameProcessing:

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{


			case sf::Event::Closed: {

				window.close();
				break;
			}

			
			case sf::Event::KeyPressed: {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {



				}
			} 


			}

		} // end of while (window.pollEvent(event))

		window.clear();
		window.draw(picture->GetSprite());
		window.draw(background->GetSprite());
		window.display();

	} // end of while (window.isOpen())
}



