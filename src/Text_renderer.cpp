#include "Text.h"
#include "SDL_ttf.h"
#include <iostream>
using namespace howling_pass;

Text_renderer::Text_renderer()
{
	font = TTF_OpenFont("media/StardosStencil-Regular.ttf", 30);
	if (font == NULL) {
		printf("Null font!");
	}
}

void Text_renderer::render_text(const std::string& message,
	const SDL_Color& c, int x, int y)
{
	font_surface = TTF_RenderText_Blended(font, message.c_str(), c);
	if (font_surface == NULL) {
		printf("Oh shit!, font surface is null!");
		return;
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, font_surface->w, font_surface->h, 
		0, GL_BGRA, GL_UNSIGNED_BYTE, font_surface->pixels);

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); glVertex2i(x, y);
		glTexCoord2f(1, 0); glVertex2i(x + font_surface->w, y);
		glTexCoord2f(1, 1); glVertex2i(x + font_surface->w, y + 
			font_surface->h);
		glTexCoord2f(0, 1); glVertex2i(x, y + font_surface->h);
	}
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	glDeleteTextures(1, &texture);
	SDL_FreeSurface(font_surface);
}
