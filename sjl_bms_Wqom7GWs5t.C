#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

int main(){
	int gd,gm,maxX,maxY,originX,originY,x1,x2,y1,y2,count;
	float dx,dy,steps;
	float delx,dely,p0,pk;
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

	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dy) < abs(dx)) {
		dely = dy;
		delx = dx;
	}else {
		dely = dx;
		delx = dy;
	}


	p0 = 2 * abs(dely) - abs(delx);
	ix = x1;
	iy = y1;
	pk = p0;
	count = 1;
	while (ix != x2 && iy != y2) {
		if(count > 14) count = 1;

		if(pk < 0) {
			xinc = delx / abs(delx);
			yinc = 0;
			pk += 2 * abs(dely);
		}
		else {
			xinc = delx / abs(delx);
			yinc = dely / abs(dely);
			pk += 2 * abs(dely) - 2 * abs(delx);
		}
		delay(20);
		ix += xinc;
		iy += yinc;
		count ++;
		putpixel(originX + ix, originY - iy,count);
		putpixel(originX + 1 + ix, originY+1 - iy,count);
		putpixel(originX + 1 +ix, originY-1 - iy,count);
		putpixel(originX -1 +ix, originY+1 - iy,count);
		putpixel(originX -1 + ix, originY-1 - iy,count);
	}



	getch();
	closegraph();
	return 0;
}