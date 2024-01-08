#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "console.h"
#include "Entity.h"

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
//
//}
//


// Clean Version

int main()
{
	int windowCenterPos = 55;

	Clear();

	// Middle of screen (horizontally)
	GoToX(windowCenterPos);
	printf("Ready?");

	Sleep(2000);
	Clear();

	// Repeated
	GoToX(windowCenterPos);
	printf("Start!");

	Sleep(800);
	Clear();

	// Spawn Player
	Entity player = Entity::Entity(windowCenterPos, 1);

	Entity* bullets[5] =
	{
	new Entity(-1, 3),
	new Entity(-1, 3),
	new Entity(-1, 3),
	new Entity(-1, 3),
	new Entity(-1, 3),
	};

	Entity* enemies[5] =
	{
	new Entity(-2, 3),
	new Entity(-2, 3),
	new Entity(-2, 3),
	new Entity(-2, 3),
	new Entity(-2, 3),
	};

	while (true)
	{
		if ((GetAsyncKeyState(0x25) & 0x8000) != 0 && (GetAsyncKeyState(0x27) & 0x8000) == 0) // Left
		{
			player.Move(-1);
		}

		else if ((GetAsyncKeyState(0x27) & 0x8000) != 0 && (GetAsyncKeyState(0x25) & 0x8000) == 0) // Right
		{
			player.Move(1);
		}

		if ((GetAsyncKeyState(0x43) & 0x8000) != 0) // Shooting
		{
			for (int i = 0; i < 5; i++)
			{
				if (bullets[i]->_xPos == -1)
				{
					bullets[i]->_xPos = player._xPos + player._direction;
					bullets[i]->_direction = player._direction;
					break;
				}
			}
		}

		for (Entity* bullet : bullets)
		{
			bullet->Move();
		}

		if (bulletXPos != -1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (bulletXPos == enemyXPos)
				{
					bulletXPos = -1;
					enemyXPos = -1;
					break;
				}
				bulletXPos += (bulletDirection ? 1 : -1);
			}
		}

		if (bulletXPos > 120 || bulletXPos < 0) // Border Check
		{
			bulletXPos = -1;
		}

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
	/*	if (enemyXPos != -1)
		{
			pos.X = enemyXPos;
			SetConsoleCursorPosition(output, pos);
			printf("E");
		}*/

		Sleep(17);
	}
}
