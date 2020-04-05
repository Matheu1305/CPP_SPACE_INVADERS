#ifndef Entidade_H
#define Entidade_H
#include <iostream>
#include <string>

using namespace std;

class Entidade{
public:
	friend Entidade &operator+=(Entidade &, int);
	friend Entidade &operator-=(Entidade &, int);
	Entidade (int, int, int, int, char);
	
	void drawOff(int, int);
	void draw();
	void drawOn(int, int);
	void drawEntity();
	void drawOffEntityX(int i);
	void drawOffEntityY(int i);
	void print(int);
	void setX(int);
	void setY(int);
	void setX2(int);
	void setY2(int);
	void SetCursorPosition(int x, int y){
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = {x,y};
		SetConsoleCursorPosition(output, pos);
	}
	
	int getX();
	int getX2();
	int getY();
	int getY2();
	char getC();
		
private:
	int x;
	int y;
	int x2;
	int y2;
	char cn;			
};
#endif
