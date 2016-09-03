#ifndef GAME_H
#define GAME_H
#include "Graphics.h"
#include "Input.h"
#include "Object.h"
#include "Text.h"

#include <vector>

namespace howling_pass {

class Game {
public:

    /**
     * Constructor
     * initialises SDL systems, creates a window and an OpenGL rendering context
     * \param title The title of the app window
     * \param w Width of the app window. MUST be greater than zero
     * \param h Height of the app window. MUST be greater than zero
     * \param f Fullscreen flag. True if fullscreen desired, false otherwise
     * \throws runtime_error if bad arguments given
     * \throws runtime_error if failure to initialise window or gl_context
     * Post-Conditions: window and gl_context will be valid
     */
     Game(char* title, int w, int h, bool f);

     ~Game();

    virtual void update(Uint32 elapsed);
    virtual void quit();
    virtual void run();
    virtual void init();
    virtual void stop();
    virtual void render();

    SDL_Window* window; /**< The SDL window for this app */
    SDL_GLContext gl_context; /**< The openGL context */

    int width, height;
    char* title_text;
    bool fullscreen;

    /**
     * initialise SDL
     * \return True if successful, false otherwise
     */
    virtual bool init_sdl();

    /**
     * Init SDL window
     */
    virtual void init_window();

    /**
     * init OpenGL
     */
    virtual void init_opengl();

    virtual void init_openal();

    Input_handler* input;

    Text_renderer* text_rend;
protected:
    bool running;
    virtual void set_opengl_attirbutes();
    std::vector<Object> game_objects;
};
}
#endif
