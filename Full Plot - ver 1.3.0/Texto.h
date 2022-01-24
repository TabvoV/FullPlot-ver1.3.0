#include<iostream>
#include<conio.h>
#include"graphicsMod.h"
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;

void Texto(int posicionx, int posiciony, char *h="  "){
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(posicionx, posiciony,h);
}

