#include <stdio.h>
#include <conio.h>
#include <graphics.h>



int main(){
	int gd,gm,maxX,maxY,originX,originY;
	int x,y,r,c = WHITE;
	float p,counter;
	float ix,iy;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");


	// Draw Axis
	maxX = getmaxx();
	maxY = getmaxy();
	originX = maxX /2;
	originY = maxY /2;
	line(0,originY,maxX,originY);
	line(originX,0,originX,maxY);

	// Inputs
	printf("Enter X,Y, R: ");
	scanf("%d %d %d", &x, &y, &r);

	// Draw Center
	putpixel(originX + x, originY - y,YELLOW);
	putpixel(originX + x + 1, originY - y + 1,YELLOW);
	putpixel(originX + x + 1, originY - y,YELLOW);
	putpixel(originX + x, originY - y + 1,YELLOW);
	putpixel(originX + x -1, originY - y -1 ,YELLOW);
	putpixel(originX + x - 1, originY - y,YELLOW);
	putpixel(originX + x, originY - y - 1,YELLOW);
	putpixel(originX + x + 1, originY - y -1 ,YELLOW);
	putpixel(originX + x -1 , originY - y + 1,YELLOW);

	// Set initial values
	counter = 10;
	while(counter--) {
	c = counter ;

	ix = 0;
	iy = r + counter * 10;
	p = 5/4 - r;


	while(ix <= iy) {
		if(p < 0) {
			p += (2*ix) + 3;
		}
		else {
			p += ( 2 *ix) - (2 * iy) + 3;
		       iy --;
		}
		ix++;

		// putpixel(x + ix + originX, y + iy - originY, YELLOW);
		putpixel(x + ix + originX, originY - (y + iy), c);
		putpixel(x - ix + originX, originY - (y + iy), c);
		putpixel(x + ix + originX, originY - (y - iy), c);
		putpixel(x - ix + originX, originY - (y - iy), c);
		putpixel(x + iy + originX, originY - (y + ix), c);
		putpixel(x - iy + originX, originY - (y + ix), c);
		putpixel(x + iy + originX, originY - (y - ix), c);
		putpixel(x - iy + originX, originY - (y - ix), c);
	}
	}
	getch();
	closegraph();
	return 0;
}