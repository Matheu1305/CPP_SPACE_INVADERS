#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "Entidade.h"


using namespace std;




Entidade::Entidade(int x, int y, int x2, int y2, char c, char cn){
	this->x = x;
	this->y = y;
	this->x2 = x2;
	this->y2 = y2;
	this->c = c;
	this-> cn = cn;
}




void Entidade::drawOn(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << cn;
}

void Entidade::drawOff(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << ' ';
}

void Entidade::drawEntity() {
	for (int yS = -y2; yS < y2; yS++){
		for (int xS = -x2; xS < x2; xS++){
			drawOn(xS + x, yS + y);
		}
	}	
}
		
void Entidade::drawOffEntity(int i, char c) {
	if (c == 'x'){
		for (int yS = -y2; yS < y2; yS++){
			for (int xS = -x2-i; xS < x2-i; xS++){
				drawOff(xS + x, yS + y);
			}
		}
	}
	if (c == 'y'){
		for (int yS = -y2-i; yS < y2-i; yS++){
			for (int xS = -x2; xS < x2; xS++){
				drawOff(xS + x, yS + y);
			}
		}
	}	
		
}		
		

void Entidade::draw(){
	SetCursorPosition(x, y);
	cout << cn;
}

void Entidade::setX(int a){
	x = a;
}
void Entidade::setY(int a){
	y = a;
}
void Entidade::setX2(int a){
	x2 = a;
}
void Entidade::setY2(int a){
	y2 = a;
}


int Entidade::getX(){return x;}
int Entidade::getX2(){return x2;}
int Entidade::getY(){return y;}
int Entidade::getY2(){return y2;}
char Entidade::getC(){return c;}

Entidade &operator+=(Entidade &a, int i){
	if (a.getC() == 'x'){
		a.setX(a.getX()+i);
		a.drawOffEntity(i, a.getC());
	}
	if (a.getC() == 'y'){
		a.setY(a.getY()+i);
		a.drawOffEntity(i, a.getC());
	}
}
