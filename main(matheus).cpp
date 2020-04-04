#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

// Estas não estão na tabela ASCII!!!
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120

#include "Entidade.h"


using namespace std;

int HEIGHT = 35;
int WIDTH = 75;

char chPlayer = 'P';
char bgChar = ' ';


void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}
void SetConsoleSize(int width, int height){
	HANDLE wHnd;    // Handle to write to the console.
	HANDLE rHnd;

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Space Invaders!");
    
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
    COORD bufferSize = {width, height};
    
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void ClearScreen(const string& ch){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			SetCursorPosition(x, y);
			cout << ch;
		}
	}
}

// AGORA O JOGO
void movePlayer(int x, int y, int oldX = 0, int oldY = 0){
	SetCursorPosition(oldX, oldY);
	cout << bgChar;
	SetCursorPosition(x, y);
	cout << chPlayer;
}

int main(){
	
	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	//////////////////////////////
	
	int initX = WIDTH / 2;
	int initY = HEIGHT / 2;
	int oldX = initX;
	int oldY = initY;
	int x = initX;
	int y = initY;
	
	// posição inicial do jogador
	movePlayer(x, y);
		
	char key = getch();
    int value = key;
	
	Entidade e = Entidade(50, 25, 2, 2, 'x', 'A');
	e.drawEntity();
	Sleep(1000);
	e += -7;
	e.drawEntity();
	
	////////////////////// Game Loop
    while(value != KEY_X){
    	
    	// Ultimos valores do player, para serem "limpos"
		oldX = x;
        oldY = y;
    	
    	// movimento
        switch(getch()){
	        case KEY_UP:
	            y -= 1;
	            break;
	        case KEY_DOWN:
	            y += 1;
	            break;
	        case KEY_LEFT:
	            x -= 1;
				break;
	        case KEY_RIGHT:
	            x += 1;
				break;
        }
		
		movePlayer(x, y, oldX, oldY);	
		
        key = getch();
        value = key;
    }
	
	cin.get();
	return 0;
}
