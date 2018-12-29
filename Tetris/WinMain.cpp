#include "pch.h"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <time.h>
#include <Windows.h>
#undef min
#undef max

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
#include "BlockStack.h"
#include "GamePool.h"
#include "Menu.h"
#include "MovingBlock.h"
#include "Picture.h"
#include "Sound.h"
#include "StartMenu.h"
#include "Ranking.h"
#include "Text.h"
#include "UnitBlock.h"

#ifndef DEBUG_CONSOLE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

#ifdef DEBUG_CONSOLE
	int main() {
#endif

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

		Picture* picture = new Picture();
		Sound* soundManage = Sound::GetInstance();
		soundManage->PlayBackGroundMusic();

		Text *textManage = Text::GetInstance();

		//호출순서 주의 (GamePool이 먼저 초기화 되고, BlockStack이 초기화 되어야 함)
		GamePool* gamePool = GamePool::GetInstance();
		BlockStack* blockStacked = BlockStack::GetInstance();
		MovingBlock* movingBlock = new MovingBlock();

		Menu menu(picture->GetSelectedNumber());

		srand(time(0));
		int periodicTimer = 0;
		sf::Clock clock;

	GameProcessing:

		while (window.isOpen())
		{
			int elapsedTime = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			periodicTimer += elapsedTime;

			// movingBlock이 아래에 도달했다면, 새 movingBlock을 만든다.

			if (movingBlock->BlockReachBottom()) {
		
				delete movingBlock;
				movingBlock = new MovingBlock();
			}

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

						// 메뉴 호출

						soundManage->PauseBackGroundMusic();

						while (window.isOpen()) {

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) menu.MoveUp();

							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) menu.MoveDown();

							else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

								switch (menu.GetSelectedItemIndex()) {

								case Menu::BUTTON_PLAY:
									soundManage->PlayBackGroundMusic();
									goto GameProcessing;
									break;

								case Menu::BUTTON_GAME_RESTART:

									//////// 수정필요 ! 게임 재시작 시 싱글톤인 blockStacked를 초기화해야 한다. ////////

									// delete(blockStacked);
									goto GameStartingPoint;
									Sleep(140);
									break;

								case Menu::BUTTON_QUIT:
									window.close();
									break;
								}

							}

							window.clear();
							menu.Draw(window);
							window.display();

						}
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						// 블록 회전
						movingBlock->RotateBlock();
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						// x축으로 -1칸 이동
						movingBlock->BlockMoveLeft();
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						// x축으로 +1칸 이동
						movingBlock->BlockMoveRight();
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						// 빨리 내림
						movingBlock->SetMovingTime(FAST_BLOCK_MOVINGTIME);
					}

					break;
				}
				}


			} ///////////// end of while (window.pollEvent(event)) /////////////

			// periodicTimer가 지정된 시간 경과 시 0으로 초기화되면서, 블록을 한 칸 내린다.

			if (movingBlock->GetMovingTime() < periodicTimer)
			{
				movingBlock->BlockMoveDownByTime();
				movingBlock->SetMovingTime(DEFAULT_BLOCK_MOVINGTIME);
				blockStacked->CheckRowFulled();
				periodicTimer = 0;

			}

			window.clear(sf::Color::White);
			window.draw(picture->GetSprite());
			blockStacked->DrawBlockStacked(window);
			textManage->DrawText(window);
			movingBlock->DrawMovingBlock(window);
			window.display();

		} ///////////// end of while (window.isOpen()) /////////////
	}
