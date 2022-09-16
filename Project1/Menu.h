#pragma once
#include "User.h"
#include <Windows.h>


class Menu
{
protected:
	vector<User*> base;
	vector<User*>::iterator ind;
	
	public:
		Menu();
		~Menu();
		
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		void ConsoleCursorVisible(bool show, short size) {
			CONSOLE_CURSOR_INFO structCursorInfo;
			GetConsoleCursorInfo(hStdOut, &structCursorInfo);
			structCursorInfo.bVisible = show;
			structCursorInfo.bVisible = size;
			SetConsoleCursorInfo(hStdOut, &structCursorInfo);

		}
		void GoToXY(short x, short y) {

			SetConsoleCursorPosition(hStdOut, { x,y });
		}

		void firstM();
		void secondM(User A);
};


//Получаем дескриптор консоли



