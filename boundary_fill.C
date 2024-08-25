#include <conio.h>
#include <stdio.h>
#include <graphics.h>
int current = 0;

void ffill(int x, int y, int color){
	current = getpixel(x,y);
	if(x % 100 == 0 && y % 100 == 0) {
		sleep(1);
	}
	if(current== BLACK && x >10 && y > 10 && x < 74 && y < 74 ){
		putpixel(x,y,color);
		ffill(x,y+1,RED);
		ffill(x+1,y,YELLOW);
		sleep(1);
		ffill(x,y-1,GREEN);
		ffill(x-1,y,BLUE);
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
	rectangle(10,10,74,74);
	setcolor(RED);
	ffill(16,36,RED);

	getch();
	closegraph();
	return 0;
}