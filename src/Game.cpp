#include "Game.h"
#include "Radar_beam.h"
#include "Text.h"

#include "SDL_ttf.h"

#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <string>
using namespace howling_pass;

Game::Game(char* title, int w, int h, bool f)
    :fullscreen{ f }
{

    if (w < 0) {
        printf("Failed check!\nFile: %s Line: %d\n"
            "Tried to initialise Game with negative width!\n", __FILE__,
            __LINE__);
        throw std::runtime_error("Tried to initialise Game with negative width");
    }

    if (h < 0) {
        printf("Failed check!\nFile: %s Line: %d\n", __FILE__, __LINE__);
        printf("Tried to initialise Game with negative height!\n");
        throw std::runtime_error("Tried to initialise Game with negative"
            " height");
    }

    width = w;
    height = h;
    title_text = title;

    if (!init_sdl()) {
        printf("Failed to initialise SDL:\n"
            "File: %s Line: %d\n", __FILE__, __LINE__);
        printf("SDL Error: %s\n", SDL_GetError());
        throw std::runtime_error("Could not initialise SDL");

    }

    init_window();
    if (window == NULL) {
        printf("Failed to create SDL_Window:\n"
            "File: %s\nLine %d\n", __FILE__, __LINE__);
        printf("SDL Error: %s\n", SDL_GetError());
        throw std::runtime_error("Could not create window");
    }

    gl_context = SDL_GL_CreateContext(window);
    if (gl_context == NULL) {
        printf("Failed to create openGL context:\n"
            "File: %s Line: %d\n", __FILE__, __LINE__);
        printf("SDL Error: %s\n", SDL_GetError());
        throw std::runtime_error("Could not init openGL");
    }

    set_opengl_attirbutes();
    init_opengl();

    SDL_SetWindowTitle(window, (std::string{ title_text }.append(" OpenGL: " + std::string{ (char*) glGetString(GL_VERSION) })).c_str());

    input = new Input_handler();

    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    text_rend = new Text_renderer();
}

Game::~Game()
{
    delete[] input;
    delete[] text_rend;
    SDL_DestroyWindow(window);
}

bool Game::init_sdl()
{
    return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}

void Game::init_window()
{
    if (fullscreen) {
        window = SDL_CreateWindow(title_text, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, width, height,
            SDL_WINDOW_SHOWN|SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL);
    }
    else {
        window = SDL_CreateWindow(title_text, SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, width, height,
            SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
    }
}

void Game::init_opengl()
{
    //Enable vysnc
    if (SDL_GL_SetSwapInterval(1) != 0) {
        printf("WARNING: Could not enable vsync in openGL.\n");
    }

    GLenum error = GL_NO_ERROR;

    /* Init projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /******* IMPORTANT !!!!!!! ************/
    /* Convert coord systems to our normal system with 0, 0 in top left */
    glOrtho( 0.0, width, height, 0.0, 1.0, -1.0 );

    /* Check for error */
    error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Error initialising projection matrix!\n");
        printf("Error: %s\n", gluErrorString(error));
        throw std::runtime_error("Could not init projection matrix");
    }

    /* Initialise Model view */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Check for error */
    error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Error initialising model view matrix!\n");
        printf("Error: %s\n", gluErrorString(error));
        throw std::runtime_error("Could not init model view matrix");
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   //Set clear color

    /* Check for error */
    error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Error setting clear color for openGL!\n");
        printf("Error: %s\n", gluErrorString(error));
        throw std::runtime_error("Could not set clean color");
    }
}

void Game::init_openal()
{
    
}

void Game::update(Uint32 elapsed)
{
    glClear(GL_COLOR_BUFFER_BIT);
    input->update();
    if (input->state(Key::escape) || input->quit_requested()) {
        stop();
    }

    /** Update radar beam **/

}

void Game::render()
{
    glBegin(GL_QUADS);
    {
        glVertex2i(620, 60);
        glVertex2i(760, 60);
        glVertex2i(760, 100);
        glVertex2i(620, 100);
        //glVertex2i(620, 60);
    }
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2i(620, 60);
        glVertex2i(760, 60);
        glVertex2i(760, 100);
        glVertex2i(620, 100);
        glVertex2i(620, 60);
    }
    glEnd();
    
}

void Game::stop()
{
    running = false;
}

void Game::run()
{
    Uint32 current_time, previous_time, elapsed_time;
    previous_time = SDL_GetTicks();
    running = true;
    Radar_beam beam{ 10, 10, 290, SDL_Color{0, 249, 51, 255} };

    SDL_Color text_color{ 0, 249, 51, SDL_ALPHA_TRANSPARENT};
    while (running) {
        current_time = SDL_GetTicks();
        elapsed_time = current_time - previous_time;
        update(elapsed_time);
        printf("Mouse coord: (%d, %d)\n", input->mouse_x(), input->mouse_y());
        beam.update(elapsed_time);
        render();
        beam.render();
        text_rend->render_text("Radar v0.1.0", text_color, 40, 40);
        //printf("Frame time: %d\n", SDL_GetTicks() - current_time);
        SDL_Delay(10);
        SDL_GL_SwapWindow(window);
    }
    quit();
}

void Game::quit()
{
}

void Game::set_opengl_attirbutes()
{
}

void Game::init()
{
}
