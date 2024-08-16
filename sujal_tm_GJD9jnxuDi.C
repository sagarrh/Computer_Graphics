#include <stdio.h>
#include <conio.h>
#include <graphics.h>


int main(){
	int gd,gm,maxX,maxY,originX,originY;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	// Draw Axis
	maxX = getmaxx();
	maxY = getmaxy();
	originX = maxX /2;
	originY = maxY /2;
	line(0,originY,maxX,originY);
	line(originX,0,originX,maxY);

	getch();
	closegraph();
	return 0;
}