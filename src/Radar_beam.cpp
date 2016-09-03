#include "Radar_beam.h"

#include <cmath>
#define PI 3.14159265359
using namespace howling_pass;

/*
	Construct a radar beam that rotates about a center point, with a specified revolutions per minute
	\param x The topleft of the circle
	\param y The topleft of the circle
*/
Radar_beam::Radar_beam(int x, int y, int r)
	:radius{ r }
{
	center_x = x + radius;
	center_y = y + radius;

	x2 = center_x;
	y2 = y;
	calculate_circle_vertices();
	last_update = SDL_GetTicks();
}

Radar_beam::Radar_beam(int x, int y, int r, const SDL_Color& c)
	: Radar_beam(x, y, r)
{
	beam_color = c;
}

void Radar_beam::render()
{
	glColor3f(beam_color.r / 255.0f, beam_color.g / 255.0f, 
		beam_color.b / 255.0f);
	render_circle();
	glBegin(GL_LINES);
	glVertex2i(center_x, center_y);
	glVertex2i(x2, y2);
	glEnd();
}

void Radar_beam::render_circle()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < number_of_vertices; i++) {
		glVertex2i(circle[i].x, circle[i].y);
	}
	glEnd();
}

void Radar_beam::calculate_circle_vertices()
{
	circle = (SDL_Point*) malloc(number_of_vertices * sizeof(SDL_Point));

	for (int i = 0; i < number_of_vertices; i++) {
		int x = center_x + (radius * cos(i * PI * 2 / number_of_vertices));
		int y = center_y + (radius * sin(i * PI * 2 / number_of_vertices));
		circle[i] = SDL_Point{ x, y };
	}
}

void Radar_beam::update(Uint32 elapsed)
{
	if (elapsed - last_update > 30) {
		last_update = elapsed;
		line_end_index++;
		if (line_end_index >= number_of_vertices) {
			line_end_index = 0;
		}
		x2 = circle[line_end_index].x;
		y2 = circle[line_end_index].y;
	}
}
