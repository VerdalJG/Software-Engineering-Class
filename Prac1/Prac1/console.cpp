#include <windows.h>
#include "console.h"

void GoToX(int x)
{
    COORD pos = { static_cast<short>(x) };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void HideCursor()
{
    HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO t;
    t.bVisible = false;
    SetConsoleCursorInfo(hdl, &t);
}

void Clear()
{
    system("cls");
}