#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

int main(){
	int gd,gm,maxX,maxY,originX,originY,x1,x2,y1,y2,count;
	float dx,dy,steps;
	float xinc, yinc,ix,iy;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	// Draw Axis
	maxX = getmaxx();
	maxY = getmaxy();
	originX = maxX /2;
	originY = maxY /2;
	line(0,originY,maxX,originY);
	line(originX,0,originX,maxY);

	// Get coords
	printf("Enter X1, Y1 and X2, Y2 of line: ");
	scanf("%d %d %d %d", &x1,&y1,&x2,&y2);


	// Calc steps
	dy = (y2-y1);
	dx = (x2-x1);

	if(abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else {
		steps = abs(dy);
	}

	xinc = dx/steps;
	yinc = dy/steps;

	ix = x1;
	iy = y1;
	count = 0;
	while(ix != x2 && iy != y2){
		if(count >= 10){
			count =0;
		}

		if(count < 5 || count == 7 ) {
			putpixel(originX + ceil(ix),originY - ceil(iy),GREEN);
		}

		ix += xinc;
		iy += yinc;
		count ++;
	}

	getch();
	closegraph();
	return 0;
}