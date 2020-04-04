#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "Menu.h"

void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}

void Menu::showOptions(){
	for(int i = 0; i < options.size(); i++){
		SetCursorPosition(i * 2, 0);
		cout << options[i];
	}
}
