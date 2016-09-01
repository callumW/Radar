#ifndef TEXT_H
#define TEXT_H
#include "Graphics.h"
#include "SDL_ttf.h"
#include <string>

namespace howling_pass {

class Text_renderer {
public:
    Text_renderer();
	void render_text(const std::string& message, const SDL_Color& c, 
		int x, int y);
private:
    TTF_Font* font;
    SDL_Surface* font_surface;
};
}
#endif
