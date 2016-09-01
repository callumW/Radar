#ifndef RADAR_BEAM_H
#define RADAR_BEAM_H
#include "Object.h"
#include "Graphics.h"
namespace howling_pass {

class Radar_beam : public Object {
public:
	Radar_beam(int x, int y, int r);
	Radar_beam(int x, int y, int r, const SDL_Color& c);
	virtual void render();
	virtual void update(Uint32 elapsed);
	
private:
	const int number_of_vertices = 200;
	int center_x, center_y, x2, y2;
	float rpm;
	int radius;
	int line_end_index = 0;
	SDL_Color beam_color;
	Uint32 last_update;
	SDL_Point* circle;

	void render_circle();
	void calculate_circle_vertices();
};

}
#endif
