#include <conio.h>
#include <stdio.h>
#include <graphics.h>
int current = 0;

void bfill(int x, int y, int color){
	current = getpixel(x,y);

	if(current != color && current != WHITE){
		putpixel(x,y,RED);
		bfill(x,y+1,color);
		bfill(x+1,y,color);
		bfill(x,y-1,color);
		bfill(x-1,y,color);
	}


}

int main(){
	int gd,gm;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	//initgraph(&gd,&gm,"C:\\TurboC++\\Disk\\TurboC3\\BGI");
	//initgraph(&gd,&gm,NULL);

	// boundary
	setcolor(WHITE);
	rectangle(10,30,30,50);
	setcolor(RED);
	bfill(16,36,RED);

	setcolor(WHITE);
	rectangle(110,30,130,50);
	setcolor(RED);
	bfill(116,36,RED);


	setcolor(WHITE);
	circle(70,150,50);
	bfill(70,150,RED);

	getch();
	closegraph();
	return 0;
}