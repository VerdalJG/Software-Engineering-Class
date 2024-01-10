#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "console.h"
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

// Arrow Keys:
// Left - 25
// Up - 26
// Right - 27
// Down - 28
// C - 43



// Unorganized Version
//
//int main()
//{
//	system("cls");
//
//	// Middle of screen (horizontally)
//	COORD pos = { static_cast<short>(55), static_cast<short>(0) };
//	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	SetConsoleCursorPosition(output, pos);
//	printf("Ready?");
//
//	Sleep(2000);
//	system("cls");
//
//	// Repeated
//	SetConsoleCursorPosition(output, pos);
//	printf("Start!");
//
//	Sleep(800);
//	system("cls");
//
//	SetConsoleCursorPosition(output, pos);
//	printf("A");
//
//	// Initial player position
//	int playerXPos = 55;
//	bool playerDirection = false;
//
//	int bulletXPos = -1;
//	bool bulletDirection = false;
//
//	int enemyXPos = -1;
//	int enemySpeed = 2;
//
//	int enemySpawnCounter = 500;
//
//	while (true)
//	{
//
//		// Game Logic
//		if ((GetAsyncKeyState(0x25) & 0x8000) != 0 && (GetAsyncKeyState(0x27) & 0x8000) == 0) // Left
//		{
//			playerXPos -= 1;
//			playerDirection = false;
//		}
//
//		else if ((GetAsyncKeyState(0x27) & 0x8000) != 0 && (GetAsyncKeyState(0x25) & 0x8000) == 0) // Right
//		{
//			playerXPos += 1;
//			playerDirection = true;
//		}
//
//		if ((GetAsyncKeyState(0x43) & 0x8000) != 0) // Shooting
//		{
//			if (bulletXPos == -1)
//			{
//				int offset = playerDirection ? 1 : -1;
//				bulletXPos = playerXPos + offset;
//				bulletDirection = playerDirection;
//			}
//		}
//
//		if (enemyXPos == -1 && enemySpawnCounter < 0)
//		{
//			int spawnSide = rand() % 2;
//			enemyXPos = spawnSide ? 120 : 0;
//		}
//
//		if (enemyXPos != -1)
//		{
//			if (enemyXPos > playerXPos)
//			{
//				for (int i = 0; i < enemySpeed; i++)
//				{
//					if (playerXPos == enemyXPos) return 0;
//					if (enemyXPos == bulletXPos)
//					{
//						enemyXPos = -1;
//						bulletXPos = -1;
//						break;
//					}
//					enemyXPos += -1;
//				}
//			}
//			else if (enemyXPos < playerXPos)
//			{
//				for (int i = 0; i < enemySpeed; i++)
//				{
//					if (playerXPos == enemyXPos) return 0;
//					if (enemyXPos == bulletXPos)
//					{
//						enemyXPos = -1;
//						bulletXPos = -1;
//						break;
//					}
//					enemyXPos += 1;
//				}
//			}
//		}
//
//		if (bulletXPos != -1)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				if (bulletXPos == enemyXPos)
//				{
//					bulletXPos = -1;
//					enemyXPos = -1;
//					break;
//				}
//				bulletXPos += (bulletDirection ? 1 : -1);
//			}
//		}
//
//		if (bulletXPos > 120 || bulletXPos < 0) // Border Check
//		{
//			bulletXPos = -1;
//		}
//
//
//
//		if (enemySpawnCounter > 0)
//		{
//			enemySpawnCounter -= 17;
//		}
//
//		system("cls");
//
//		// Drawing
//
//		CONSOLE_CURSOR_INFO t;
//		t.bVisible = false;
//		SetConsoleCursorInfo(output, &t);
//
//		// Player
//		pos.X = playerXPos;
//		SetConsoleCursorPosition(output, pos);
//		printf("A");
//
//		// Bullets
//		if (bulletXPos != -1)
//		{
//			pos.X = bulletXPos;
//			SetConsoleCursorPosition(output, pos);
//			printf("o");
//		}
//
//		// Enemies
//		if (enemyXPos != -1)
//		{
//			pos.X = enemyXPos;
//			SetConsoleCursorPosition(output, pos);
//			printf("E");
//		}
//
//		Sleep(17);
//	}
//}


// Clean Version

void StartSequence(int pos);

int main()
{
	int windowCenterPos = 55;

	StartSequence(windowCenterPos);

	// Spawn Player
	Player player = Player::Player(1);

	int enemySpawnCounter = 500;

	Entity* bullets[5] =
	{
	new Bullet(),
	new Bullet(),
	new Bullet(),
	new Bullet(),
	new Bullet(),
	};

	Entity* enemies[5] =
	{
	new Enemy(&player),
	new Enemy(&player),
	new Enemy(&player),
	new Enemy(&player),
	new Enemy(&player),
	};

	while (true)
	{
		if ((GetAsyncKeyState(0x25) & 0x8000) != 0 && (GetAsyncKeyState(0x27) & 0x8000) == 0) // Left
		{
			player.Move(-1);
			player.CollisionCheck(enemies[0]);
		}

		else if ((GetAsyncKeyState(0x27) & 0x8000) != 0 && (GetAsyncKeyState(0x25) & 0x8000) == 0) // Right
		{
			player.Move(1);
			player.CollisionCheck(enemies[0]);
		}

		if ((GetAsyncKeyState(0x43) & 0x8000) != 0) // Shooting
		{
			for (int i = 0; i < 5; i++)
			{
				if (bullets[i]->_xPos == -1)
				{
					bullets[i]->Spawn(player._xPos, player._direction);
					break;
				}
			}
		}

		for (Entity* bullet : bullets)
		{
			if (bullet->_xPos != -1)
			{
				for (int i = 0; i < bullet->_speed; i++)
				{
					bullet->Move();
					if (bullet->CollisionCheck(enemies[0])) break;
					
				}
			}
		}

		for (Entity* enemy : enemies)
		{
			if (enemy->_xPos != -1)
			{
				for (int i = 0; i < enemy->_speed; i++)
				{
					enemy->Move();
					if (enemy->CollisionCheck(bullets[0])) break;
				}
			}
			else if (enemy->_xPos == -2 && enemySpawnCounter < 0)
			{
				enemy->Spawn();
				enemySpawnCounter = 500;
			}
			
		}

		if (enemySpawnCounter > 0)
		{
			enemySpawnCounter -= 17;
		}

		if (!player._alive) return 0;

		// Drawing
		Clear();
		HideCursor();

		// Player
		GoToX(player._xPos);
		printf("A");

		// Bullets
		for (Entity* bullet : bullets)
		{
			if (bullet->_xPos < 0) continue;
			GoToX(bullet->_xPos);
			printf("o");
		}

		// Enemies
		for (Entity* enemy : enemies)
		{
			if (enemy->_xPos < 0) continue;
			GoToX(enemy->_xPos);
			printf("E");
		}

		Sleep(17);
	}
}

void StartSequence(int pos)
{
	Clear();

	// Middle of screen (horizontally)
	GoToX(pos);
	printf("Ready?");

	Sleep(2000);
	Clear();

	// Repeated
	GoToX(pos);
	printf("Start!");

	Sleep(800);
	Clear();
}
