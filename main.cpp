#include <iostream>
#include "tgaimage.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void draw_line(int x0, int y0, int x1, int y1, TGAImage* img, TGAColor clr){
	for(float t = .0; t < 1.; t += .001){
		int x = x0*(1 - t) + x1 * t;
		int y = y0*(1 - t) + y1 * t;
		img -> set(x, y, clr);
	}
}

void radial(TGAImage* img, TGAColor clr, int offsetX, int step){
	int cx = img -> get_width() >> 1;
	int cy = img -> get_height() >> 1;
	for(int x = offsetX; x < img -> get_width(); x += step){
		draw_line(cx, cy, x, cy * 2, img, clr);
	}
}

int main(int argc, char** argv) {
	TGAImage image(1000, 1000, TGAImage::RGB);
	//draw_line(0, 0, 50, 50, &image, TGAColor(255,0,0,255));
	radial(&image, TGAColor(255,0,0,255), 0, 20);
	image.write_tga_file("output.tga");
	return 0;
}

