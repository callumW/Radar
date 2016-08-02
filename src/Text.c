/*
    File: Text.c
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

#include "Text.h"
#include "Window.h" //for access to renderer
#include <stdio.h>

SDL_Texture* g_charset_texture = NULL;
const int char_width = 6;
const int char_height = 5;

int initialise_charset(const struct color* c)
{
    FILE* font_file = NULL;
    font_file = fopen("../Font", "r");
    if (font_file == NULL) {
        printf("Failed to open font file!");
        return 1;
    }

    return load_from_font_file(font_file, c);
}

int load_from_font_file(FILE* font_f, const struct color* col)
{

    g_charset_texture = SDL_CreateTexture(g_renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, 36*6, 5);

    if (g_charset_texture == NULL) {
        printf("Failed to initialise character set!\nError: %s\n",
        SDL_GetError());
        return 1;
    }

    SDL_SetRenderTarget(g_renderer, g_charset_texture);

    int c = fgetc(font_f);
    int line_count = 0;
    int char_count = 0;
    int x = 0;
    int y = 0;
    /* Make the whole texture transparent first */
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
    SDL_RenderClear(g_renderer);
    SDL_SetRenderDrawColor(g_renderer, col->r, col->g, col->b, col->a);

    x = 0;
    y = 0;
    while (c != EOF) {
/*
        printf("\nLine count: %d\n", line_count);
        printf("Char count: %d\n", char_count);
        printf("Char: %c\n", c);
        printf("x: %d, y: %d\n", x, y);
*/
        if (x > 5 || y > 6) {
            printf("We tried to draw outside of font texture!\n");
            return 1;
        }

        switch (c) {
        case '\n':
            line_count++;
            y++;
            x = 0;
            if (line_count % 6 == 0) { //if we have incremented another 6 lines
                char_count++;   //we have parsed another character
                y = 0;
            }
            break;
        case '#':
            SDL_RenderDrawPoint(g_renderer, x + char_count*6, y);
            x++;
            break;
        default:
            //SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0);
            //SDL_RenderDrawPoint(g_renderer, x+char_count*6, y);
            x++;
            break;
        }
        c = fgetc(font_f);
    }

    SDL_SetRenderTarget(g_renderer, NULL);
    return 0;
    fclose(font_f);
}

void draw_string(char* text, int x, int y, int scale, int spacing)
{
    //int size = sizeof(text) / sizeof(char);
    int i = 0;
    while (text[i] != '\0') {
        draw_char(text[i], x + i*char_width*scale + spacing, y, scale);
        i++;
    }
}

void draw_char(char c, int x, int y, int scale)
{
    //printf("Drawing: %c\n", c);
    if (c == ' ')
        return;

    SDL_Rect destination = {x, y, char_width*scale, char_height*scale};
    int source_x = get_x(c);
    //printf("Which has position: %d in the charset.\n", source_x);
    SDL_Rect source = {source_x*char_width, 0, char_width, char_height};
    SDL_RenderCopy(g_renderer, g_charset_texture, &source, &destination);
}

int get_x(char c)
{
    if (c>='A' && c<='Z')
        return c - 'A';
    else if (c>='a' && c<='z')
        return c - 'a';
    else if (c>='0' && c<= '9')
        return c - '0' + 26;
    else
        return 0;
}
