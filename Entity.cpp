#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "Entity.h"

using namespace std;

void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}

Entity::Entity(int x, int y, int sAX, int sAY, char ch){
	this->x = x;
	this->y = y;
	this->ch = ch;
	this->spaceAlocatedX = sAX;
	this->spaceAlocatedY = sAY;	
}

// Dar print à posição central da Entity
void Entity::showPosition(){
	cout << "[" << x << ", " << y << "]";
}

// Desenhar o ch em x e y
void Entity::draw(){
	SetCursorPosition(x, y);
	cout << ch;
}

// Desenhar o ch num x e y escolhido por nós
void Entity::drawOn(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << ch;
}

// Desenhar o ch num quadrado de tamanho definido pelo user
void Entity::drawEntity() {
	for (int yS = -spaceAlocatedY; yS < spaceAlocatedY; yS++){
		for (int xS = -spaceAlocatedX; xS < spaceAlocatedX; xS++){
			drawOn(xS + x, yS + y);
		}
	}
}
