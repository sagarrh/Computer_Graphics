#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawMidpointCircle(int xc, int yc, int r, int color) {
    int ix = 0, iy = r;
    float p = 5.0 / 4.0 - r;

    while (ix <= iy) {
        putpixel(xc + ix, yc - iy, color);
        putpixel(xc - ix, yc - iy, color);
        putpixel(xc + ix, yc + iy, color);
        putpixel(xc - ix, yc + iy, color);
        putpixel(xc + iy, yc - ix, color);
        putpixel(xc - iy, yc - ix, color);
        putpixel(xc + iy, yc + ix, color);
        putpixel(xc - iy, yc + ix, color);

        if (p < 0) {
            p += (2 * ix) + 3;
        } else {
            p += (2 * ix) - (2 * iy) + 3;
            iy--;
        }
        ix++;
    }
}

void drawBresenhamCircle(int xc, int yc, int r, int color) {
    int d = 3 - 2 * r;
    int ix = 0, iy = r;

    while (ix <= iy) {
        putpixel(xc + ix, yc - iy, color);
        putpixel(xc - ix, yc - iy, color);
        putpixel(xc + ix, yc + iy, color);
        putpixel(xc - ix, yc + iy, color);
        putpixel(xc + iy, yc - ix, color);
        putpixel(xc - iy, yc - ix, color);
        putpixel(xc + iy, yc + ix, color);
        putpixel(xc - iy, yc + ix, color);

        if (d < 0) {
            d = d + 4 * ix + 6;
        } else {
            d = d + 4 * (ix - iy) + 10;
            iy--;
        }
        ix++;
    }
}

void drawAxis(int originX, int originY) {
    int maxX = getmaxx();
    int maxY = getmaxy();
    line(0, originY, maxX, originY); // X-axis
    line(originX, 0, originX, maxY); // Y-axis
}

void drawConcentricCircles(int originX, int originY, int initialRadius, int step, int numCircles, int choice) {
    int i;
    for (i = 0; i < numCircles; i++) {
        int r = initialRadius + i * step;
        if (choice == 1) {
            drawMidpointCircle(originX, originY, r, WHITE);
        } else if (choice == 2) {
            drawBresenhamCircle(originX, originY, r, WHITE);
        }
    }
}

int main() {
    int gd, gm, choice, r, step, numCircles;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    // Draw Axis
    int maxX = getmaxx();
    int maxY = getmaxy();
    int originX = maxX / 2;
    int originY = maxY / 2;
    drawAxis(originX, originY);

    // Menu
    printf("Choose an option:\n");
    printf("1. Draw single circle using Midpoint Algorithm\n");
    printf("2. Draw single circle using Bresenham Algorithm\n");
    printf("3. Draw concentric circles using Midpoint Algorithm\n");
    printf("4. Draw concentric circles using Bresenham Algorithm\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        // Input radius
        printf("Enter radius: ");
        scanf("%d", &r);

        // Draw Circle based on choice
        if (choice == 1) {
            drawMidpointCircle(originX, originY, r, WHITE);
        } else if (choice == 2) {
            drawBresenhamCircle(originX, originY, r, WHITE);
        }
    } else if (choice == 3 || choice == 4) {
        // Input parameters for concentric circles
        printf("Enter initial radius: ");
        scanf("%d", &r);
        printf("Enter step size between circles: ");
        scanf("%d", &step);
        printf("Enter number of circles: ");
        scanf("%d", &numCircles);

        // Draw Concentric Circles based on choice
        drawConcentricCircles(originX, originY, r, step, numCircles, choice == 3 ? 1 : 2);
    } else {
        printf("Invalid choice!\n");
    }

    getch();
    closegraph();
    return 0;
}
