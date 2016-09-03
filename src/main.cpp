#include "Graphics.h"
#include "Game.h"
#include "al.h"

using namespace howling_pass;

#undef main
int main(int argc, char* argv[])
{
    Game my_game = Game("Radar v0.1.0", 800, 600, false);
    my_game.run();
    SDL_Quit();
    return 0;
}
