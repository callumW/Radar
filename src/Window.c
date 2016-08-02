/*
    File: Window.c
    Author: Callum Wilson callum.w@outlook.com
    Description: Functions and variables relating to the game window and
    rendering to it.
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
#include "Window.h"
#include "Game.h"
SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

int gc_win_width = 800;
int gc_win_height = 600;
//const char* gc_title = "Radar v0.1";

long g_frames = 0;
char g_title_text[] = "Radar v0.0.0 FPS: 000";

BOOL g_fullscreen = FALSE;

void clear_screen()
{
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_renderer);
}

void show_screen()
{
    SDL_RenderPresent(g_renderer);
}

int initialise_window()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) < 0) {
        printf("Failed to initialise SDL!\nError: %s\n", SDL_GetError());
        return 1;
    }
    if (g_fullscreen == TRUE) {
        g_window = SDL_CreateWindow(g_title_text, 20, 20, 1280,
            800, SDL_WINDOW_SHOWN|SDL_WINDOW_FULLSCREEN_DESKTOP);
        gc_win_width = 1280;
        gc_win_height = 800;    //TODO Make this better!!!
    }
    else {
        g_window = SDL_CreateWindow(g_title_text, SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, gc_win_width,
            gc_win_height, SDL_WINDOW_SHOWN);
    }

    if (g_window == NULL) {
        printf("Failed to create SDL Window!\nError: %s\n", SDL_GetError());
        return 2;
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED|
    SDL_RENDERER_PRESENTVSYNC);

    if (g_renderer == NULL) {
        printf("Failed to create SDL Renderer!\nError: %s\n", SDL_GetError());
        return 3;
    }
    return 0;
}

void print_fps(int fps)
{
    if (fps > 999) {
        fps = 999;
    }
    else {
        int hundreds = fps / 100;
        fps -= hundreds * 100;
        int tens = fps / 10;
        fps -= tens * 10;

        g_title_text[16] = '0' + hundreds;
        g_title_text[17] = '0' + tens;
        g_title_text[18] = '0' + fps;

        SDL_SetWindowTitle(g_window, g_title_text);
    }
}
