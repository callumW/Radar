/*
    File: Game.c
    Author: Callum Wilson callum.w@outlook.com
    Description: Gameplay related functions for the radar-turn-based game.
    Date: 2016/07/28

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

#include "Game.h"
#include "HUD.h"
#include "Bool.h"
#include "SDL_opengl.h"
#include "Draw.h"

long g_previous_time = 0;
long g_current_time = 0;
long g_start_time = 0;

int g_radar_beam_y = 0;
const float gc_radar_beam_speed = 0.15f;
const int gc_radar_beam_delay = 500;
int g_scan_start_time = 0;
int g_last_scan_end = 0;
BOOL g_scanning = TRUE;

void draw_all()
{
	float r, g, b;
    glClear(GL_COLOR_BUFFER_BIT);
    r = (float) g_border_color.r / 255;
    g = (float) g_border_color.g / 255;
    b = (float) g_border_color.b / 255;
    glColor3f(r, g, b);
    //draw_line(0, 0, 20, 20);
    draw_hud();
}

void update()
{
    g_frames++;
    update_radar_beam();
}

void init_timers()
{
    g_start_time = SDL_GetTicks();
    g_current_time = g_start_time;
    g_scan_start_time = g_start_time;
    g_previous_time = 0;
}

void update_timers()
{
    g_previous_time = g_current_time;
    g_current_time = SDL_GetTicks();
}

void update_radar_beam()
{
    if (g_scanning == TRUE) {
        g_radar_beam_y = (g_current_time - g_scan_start_time) *
            gc_radar_beam_speed;
        if (g_radar_beam_y > gc_win_height - gc_padding) {
            g_scanning = FALSE;
            g_radar_beam_y = gc_padding;
            g_last_scan_end = SDL_GetTicks();
        }
    }
    else {
        if (g_current_time - g_last_scan_end > gc_radar_beam_delay)
            g_scanning = TRUE;
        g_scan_start_time = SDL_GetTicks();
    }
}
