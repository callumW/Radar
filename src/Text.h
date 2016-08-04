/*
    File: Text.h
    Author: Callum Wilson
    Description: Provides text to SDL, without the need for a charset image or
        SDL_ttf, by manually creating a SDL_Texture and drawing a charset on it
        pixel by pixel. Next time I go anywhere without internet I need to make
        sureI have an image manipulation app with me...
    Date: 2016/07/27

COPYRIGHT (c) 2016 Callum Wilson

MIT License

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



     _    _               _ _               _____
    | |  | |             | (_)             |  __ \
    | |__| | _____      _| |_ _ __   __ _  | |__) |_ _ ___ ___
    |  __  |/ _ \ \ /\ / / | | '_ \ / _` | |  ___/ _` / __/ __|
    | |  | | (_) \ V  V /| | | | | | (_| | | |  | (_| \__ \__ \
    |_|  |_|\___/ \_/\_/ |_|_|_| |_|\__, | |_|   \__,_|___/___/
                                    __/ |
                                   |___/
               _____
              / ____|
             | |  __  __ _ _ __ ___   ___  ___
             | | |_ |/ _` | '_ ` _ \ / _ \/ __|
             | |__| | (_| | | | | | |  __/\__ \
              \_____|\__,_|_| |_| |_|\___||___/
*/

#ifndef TEXT_H
#define TEXT_H

#include "SDL.h"
#include "Color.h"
#include <stdio.h>

extern SDL_Texture* g_charset_texture;

/*
    Draw the characters onto the charset texture.
    \param c The desired color of the text
*/
int initialise_charset(const struct color* c);

/*
    Read in the specified font file and draw it to the font texture.
    \param font_f The font file
    \param col The desired color of the text
*/
int load_from_font_file(FILE* font_f, const struct color* col);

/*
    Draw the specified array of characters on screen at the specified coords
    \param text The char array to draw on screen
    \param x The x coord to draw at
    \param y The y coord to draw at
    \param scale The scale to draw at
*/
void draw_string(char* text, int x, int y, int scale, int spacing);

/*
    Draw the specified character on screen at the specified coords
    \param c The character draw
    \param x The x coord to draw at
    \param y The y coord to draw at
    \param scale The scale to draw at
*/
void draw_char(char c, int x, int y, int scale);

/*
    Get the x coord in the charset texture that represents this character.
    \param c The desired character.
    \return int The x coord of the character, if the character is not in the
    charset then 0 is returned (i.e. the first character).
*/
int get_x(char c);
#endif
