#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;

class Entity {
	
	public:
		Entity(int, int, int, int, char);
		void showPosition();
		void draw();
		void drawOn(int, int);
		void drawEntity();

	private:
		int spaceAlocatedX;
		int spaceAlocatedY;
		int x;
		int y;
		char ch;
};

#endif
