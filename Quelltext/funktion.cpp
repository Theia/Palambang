#include <iostream>
#include <windows.h>
#include <math.h>
#include "funktion.h"



using namespace std;



void Textcolor(unsigned short color){
     SetConsoleTextAttribute(::GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Curpos(unsigned short x,unsigned short y){
	COORD p;
	p.X = x;
	p.Y = y;
	SetConsoleCursorPosition(::GetStdHandle(STD_OUTPUT_HANDLE),p);
}



