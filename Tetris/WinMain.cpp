#include "pch.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
#include "MovingBlockShade.h"
#include "NextBlock.h"
#include "Image.h"
#include "Sound.h"
#include "StartMenu.h"
#include "Ranking.h"
#include "Text.h"
#include "UnitBlock.h"


#ifndef DEBUG_CONSOLE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#endif

#ifdef DEBUG_CONSOLE
	int main()
	{
#endif

	StartMenuPoint:

		sf::RenderWindow startWindow(sf::VideoMode(1000, 651), GAME_TITLE);
		sf::Vector2i MousePosition;
		sf::Event MenuEvent;
		StartMenu startMenu;

		while (startWindow.isOpen())
		{
			while (startWindow.pollEvent(MenuEvent))
			{
				switch (MenuEvent.type)
				{

				case sf::Event::Closed:
				{

					startWindow.close();
					exit(0);
					break;

				}
				case sf::Event::KeyPressed:
				{

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) startMenu.MoveUp();

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) startMenu.MoveDown();

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{

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

		/*
		///////////// 호출순서 주의 /////////////

		GamePool이 먼저 초기화 되고, BlockStack이 초기화 되어야 하고
		Sound가 먼저 초기화 되고 Text가 초기화 되어야함 (클래스 내부에서 사용)
		*/

		Image* image = Image::GetInstance();
		Sound* soundManage = Sound::GetInstance();
		soundManage->PlayBackGroundMusic();

		Text *textManage = Text::GetInstance();
		Ranking *rankManage = Ranking::GetInstance();

		GamePool* gamePool = GamePool::GetInstance();
		BlockStack* blockStacked = BlockStack::GetInstance();
		
		NextBlock* nextBlock = new NextBlock();
		MovingBlock* movingBlock = new MovingBlock();
		MovingBlockShade* movingBlockShade = new MovingBlockShade();

		Menu menu(image->GetSelectedNumber());

		srand(time(0));

		// 1초 마다 점수를 증가시키기 위한 타이머
		float periodicTimer = 0;

		// 블록이 아래로 내려오는 시간을 재는 타이머
		float blockMovingTimer = 0;

		// 블록이 땅에 닿았나 판정하는 타이머
		float blockReachDownTimer = 0;

		// 플레이 시간을 나타냄
		int elapsedTimeWhilePlaying = 0;

		sf::Clock clock;

	GameProcessing:

		while (window.isOpen())
		{
			float elapsedTime = clock.getElapsedTime().asSeconds();
			clock.restart();
			periodicTimer += elapsedTime;
			blockMovingTimer += elapsedTime;
			blockReachDownTimer += elapsedTime;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				case sf::Event::KeyPressed: {

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						// 메뉴 호출
						soundManage->PauseBackGroundMusic();

						while (window.isOpen())
						{
							sf::Event menuEvent;

							while (window.pollEvent(menuEvent))
							{

								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) menu.MoveUp();

								else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) menu.MoveDown();

								else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
								{
									switch (menu.GetSelectedItemIndex())
									{

									case Menu::BUTTON_PLAY:
										soundManage->PlayBackGroundMusic();
										goto GameProcessing;
										break;

									case Menu::BUTTON_GAME_RESTART:

										delete textManage;
										delete soundManage;
										delete movingBlock;
										delete blockStacked;
										delete movingBlockShade;
										delete image;
										delete nextBlock;

										rankManage->ResetPlayerScore();

										goto GameStartingPoint;
										break;

									case Menu::BUTTON_QUIT:

										delete textManage;
										delete soundManage;
										delete movingBlock;
										delete blockStacked;
										delete movingBlockShade;
										delete image;
										delete nextBlock;
										delete rankManage;
										exit(0);
									
										break;
									}
								}
							}
							window.clear();
							menu.Draw(window);
							textManage->DrawTextWhileGame(window);
							window.display();
						}
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
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
						soundManage->PlayBlockDownFaster();
						movingBlock->SetMovingTime(FAST_BLOCK_MOVINGTIME);
					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						// 블록 바로 내리기
						soundManage->PlayBlockDown();

						while (!movingBlock->BlockReachBottom(true))
						{
							movingBlock->BlockMoveDownByTime();
						}

						delete movingBlock;
						movingBlock = new MovingBlock(nextBlock->GetBlockShape(), nextBlock->GetBlockColor());
						delete nextBlock;
						nextBlock = new NextBlock();
					}
					break;
				}
				}
			} ///////////// end of while (window.pollEvent(event)) /////////////

			// 한 줄이 찼다면 지움.
			// 미구현 : 2행 삭제 시 Great, 3행 이상 삭제 시 Excellent => 이미지 렌더링할 새 쓰레드가 필요
			while (blockStacked->CheckRowFulled()) {
				break;
			}

			movingBlockShade->UpdateBlockShade(*movingBlock);

			if (blockReachDownTimer > 0.3)
			{
				// movingBlock이 아래에 도달했다면, 새 movingBlock을 만든다.
				if (movingBlock->BlockReachBottom(true) == true)
				{
					delete movingBlock;
					movingBlock = new MovingBlock(nextBlock->GetBlockShape(), nextBlock->GetBlockColor());
					delete nextBlock;
					nextBlock = new NextBlock();			
				}
				blockReachDownTimer = 0;
			}

			// periodicTimer가 지정된 시간 경과 시 0으로 초기화되면서, 블록을 한 칸 내린다.
			if (blockMovingTimer > movingBlock->GetMovingTime())
			{
				movingBlock->BlockMoveDownByTime();
				movingBlock->SetMovingTime(DEFAULT_BLOCK_MOVINGTIME);
				blockMovingTimer = 0;
			}

			// 1초당 점수 50점 씩 증가
			if (periodicTimer >= 1)
			{
				rankManage->AddPlayerScore(50);
				elapsedTimeWhilePlaying++;
				textManage->UpdateElapsedTime(elapsedTimeWhilePlaying);
				periodicTimer = 0;
			}

			// 게임 종료 조건 
			if (blockStacked->IsGameEnd())
			{
				soundManage->PauseBackGroundMusic();

				while (window.isOpen())
				{
					sf::Event gameEndEvent;

					while (window.pollEvent(gameEndEvent))
					{
						switch (gameEndEvent.type)
						{
						case sf::Event::Closed:
						{
							window.close();

							/*delete textManage;
							delete soundManage;
							delete movingBlock;
							delete blockStacked;
							delete movingBlockShade;
							delete image;
							delete nextBlock;
							delete rankManage;*/
							
							break;
						}
						}
					}
					window.clear(sf::Color::White);
					image->DrawBackGround(window);
					blockStacked->DrawBlockStacked(window);
					textManage->DrawTextAfterGame(window);
					window.display();
				}
			}

			window.clear(sf::Color::White);
			image->DrawBackGround(window);
			image->DrawNextBlockPanel(window);
			blockStacked->DrawBlockStacked(window);
			textManage->DrawTextWhileGame(window);
			nextBlock->DrawNextBlock(window);
			movingBlockShade->DrawMovingBlockShade(window);
			movingBlock->DrawMovingBlock(window);
			window.display();

		} ///////////// end of while (window.isOpen()) /////////////

	}

	// 버그로 사용하지 않음

	//void ImageProcess(sf::RenderWindow* window)
	//{
	//	int rowFullNumber = 0;
	//	Image *image = Image::GetInstance();

	//	window->setActive(true);
	//	window->draw(image->GetExcellentSprite());
	//	window->display();
	//	Sleep(3000);

	//	while (window->isOpen())
	//	{

	//		if (rowFullNumber == 2)
	//		{
	//			window->draw(image->GetGoodjobSprite());
	//			window->display();
	//			Sleep(3000);
	//		}
	//		else if (rowFullNumber > 3)
	//		{
	//			window->draw(image->GetExcellentSprite());
	//			window->display();
	//			Sleep(3000);

	//		}

	//	}

	//}