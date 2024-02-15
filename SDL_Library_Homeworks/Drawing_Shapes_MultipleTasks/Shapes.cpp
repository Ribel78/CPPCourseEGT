#include "Shapes.h"

/*Draw Circle using Midpoint Circle Algorithm
renderer - renderer context
centerX, centerY - center of circle
radius - radius in pixels
*/
void Shapes::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) { 
	const int diameter = radius * 2;
	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;
	while (x >= y) {
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
		if (error <= 0) {
			y++;
			error += ty;
			ty += 2;
		}
		if (error > 0) {
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}
}

/* Draw Circle using Bresenham's Circle Algorithm
 ALGORITHM source: https://www.javatpoint.com/computer-graphics-bresenhams-circle-algorithm
renderer - renderer context
centerX, centerY - center of circle
radius - radius in pixels
*/
void Shapes::drawCircleB(SDL_Renderer* renderer, int centerX, int centerY, int radius) { 
	int d = 3 - 2* radius;
	int x = 0;
	int y = radius;
	while(x <= y) {
		SDL_RenderDrawPoint(renderer, (x + centerX), (y + centerY));
		SDL_RenderDrawPoint(renderer, (y + centerX), (x + centerY));
		SDL_RenderDrawPoint(renderer, (-y + centerX), (x + centerY));
		SDL_RenderDrawPoint(renderer, (-x + centerX), (y + centerY));
		SDL_RenderDrawPoint(renderer, (-x + centerX), (-y + centerY));
		SDL_RenderDrawPoint(renderer, (-y + centerX), (-x + centerY));
		SDL_RenderDrawPoint(renderer, (y + centerX), (-x + centerY));
		SDL_RenderDrawPoint(renderer, (x + centerX), (-y + centerY));
		if(d < 0){
			d = d + (4*x) + 6;
			x = x + 1;
		}
		if(d >= 0){
			d = d + 4*(x-y) + 10;
			x = x + 1;
			y = y - 1;
		}
	}
}

const double PI = 3.14159265359; //value of pi
/*
Draw a pentagon by given position coordinates and side lenght
*/
void Shapes::drawPentagon(SDL_Renderer *renderer, int centerX, int centerY, int side){
	int x, y;
	int n = 5;
	double angle = (2*PI)/n;
	double radius = side/(2*sin(PI/n));
	SDL_Point points[n+1];
	for (int i = 0; i < n+1 ; ++i){
		y = (int)round(sin(angle*i)*radius);
		x = (int)round(cos(angle*i)*radius);
		points[i] = {x+centerX, y+centerY};
	}
	const SDL_Point *pts = points;
	SDL_RenderDrawLines(renderer, pts, n+1);
}
/*
Draw a hexagon by given position coordinates and side lenght
*/
void Shapes::drawHexagon(SDL_Renderer *renderer, int centerX, int centerY, int side){
	int x, y;
	int n = 6;
	double angle = (2*PI)/n;
	double radius = side/(2*sin(PI/n));
	SDL_Point points[n+1];
	for (int i = 0; i < n+1 ; ++i){
		y = (int)round(sin(angle*i)*radius);
		x = (int)round(cos(angle*i)*radius);
		points[i] = {x+centerX, y+centerY};
	}
	const SDL_Point *pts = points;
	SDL_RenderDrawLines(renderer, pts, n+1);
}
/*
Draw a regular polygon by given position coordinates and number of sides
*/
void Shapes::drawRegularPolygon(SDL_Renderer *renderer, int centerX, int centerY, int num_sides, int radius){
	int x, y;
	double angle = (2*PI)/num_sides;
	SDL_Point points[num_sides+1];
	for (int i = 0; i < num_sides+1 ; ++i){
		y = (int)round(sin(angle*i)*radius);
		x = (int)round(cos(angle*i)*radius);
		points[i] = {x+centerX, y+centerY};
	}
	const SDL_Point *pts = points;
	SDL_RenderDrawLines(renderer, pts, num_sides+1);
}

/* Midpoint ellipse drawing algorithm
 CODE source https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/
 This code is contributed by Akanksha Rai
 Draw Ellipse using Midpoint Ellipse Algorithm by given ellipses' center coordinates and x and y radius
 */
void Shapes::drawEllipse(SDL_Renderer *renderer, int xc, int yc, int rx, int ry)
{
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	// Initial decision parameter of region 1
	d1 = (ry * ry) - (rx * rx * ry) + 
					(0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	// For region 1
	while (dx < dy) 
	{
		SDL_RenderDrawPoint(renderer, x + xc, y + yc);
		SDL_RenderDrawPoint(renderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(renderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(renderer, -x + xc, -y + yc);

		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + 
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);

	while (y >= 0)
	{
		SDL_RenderDrawPoint(renderer, x + xc, y + yc);
		SDL_RenderDrawPoint(renderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(renderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(renderer, -x + xc, -y + yc);

		if (d2 > 0) 
		{
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
}

void Shapes::drawRectangleWithBorder(SDL_Renderer *renderer, int posX, int posY, int width, int height, int borderSize){

	SDL_SetRenderDrawColor(renderer, Shapes::rgb[0], Shapes::rgb[1], Shapes::rgb[2], 255);
	SDL_Rect outerRect = {posX, posY, width, height};
	SDL_RenderFillRect(renderer, &outerRect);

	SDL_SetRenderDrawColor(renderer, Shapes::rgb[1], Shapes::rgb[2], Shapes::rgb[0], 255);
	SDL_Rect innerRect = {posX+borderSize, posY+borderSize, width-(2*borderSize), height-(2*borderSize)};
	SDL_RenderFillRect(renderer, &innerRect);

}
int Shapes::rgb[3] = {0,0,0};
int Shapes::reguarPolygonSides = 3;