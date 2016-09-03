#include "Input.h"

using namespace howling_pass;

Input_handler::Input_handler()
{
    for (int i=0; i<num_of_keys; i++) {
        key_states[i] = false;
    }
}

Input_handler::~Input_handler()
{
}

void Input_handler::update()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_q:
                key_states[int(Key::q)] = true;
                break;
            case SDLK_w:
                key_states[int(Key::w)] = true;
                break;
            case SDLK_e:
                key_states[int(Key::e)] = true;
                break;
            case SDLK_r:
                key_states[int(Key::r)] = true;
                break;
            case SDLK_t:
                key_states[int(Key::t)] = true;
                break;
            case SDLK_y:
                key_states[int(Key::y)] = true;
                break;
            case SDLK_u:
                key_states[int(Key::u)] = true;
                break;
            case SDLK_i:
                key_states[int(Key::i)] = true;
                break;
            case SDLK_o:
                key_states[int(Key::o)] = true;
                break;
            case SDLK_p:
                key_states[int(Key::p)] = true;
                break;
            case SDLK_a:
                key_states[int(Key::a)] = true;
                break;
            case SDLK_s:
                key_states[int(Key::s)] = true;
                break;
            case SDLK_d:
                key_states[int(Key::d)] = true;
                break;
            case SDLK_f:
                key_states[int(Key::f)] = true;
                break;
            case SDLK_g:
                key_states[int(Key::g)] = true;
                break;
            case SDLK_h:
                key_states[int(Key::h)] = true;
                break;
            case SDLK_j:
                key_states[int(Key::j)] = true;
                break;
            case SDLK_k:
                key_states[int(Key::k)] = true;
                break;
            case SDLK_l:
                key_states[int(Key::l)] = true;
                break;
            case SDLK_z:
                key_states[int(Key::z)] = true;
                break;
            case SDLK_x:
                key_states[int(Key::x)] = true;
                break;
            case SDLK_c:
                key_states[int(Key::c)] = true;
                break;
            case SDLK_v:
                key_states[int(Key::v)] = true;
                break;
            case SDLK_b:
                key_states[int(Key::b)] = true;
                break;
            case SDLK_n:
                key_states[int(Key::n)] = true;
                break;
            case SDLK_m:
                key_states[int(Key::m)] = true;
                break;
            case SDLK_LSHIFT:
                key_states[int(Key::shift)] = true;
                break;
            case SDLK_RSHIFT:
                key_states[int(Key::shift)] = true;
                break;
            case SDLK_LCTRL:
                key_states[int(Key::ctrl)] = true;
                break;
            case SDLK_RCTRL:
                key_states[int(Key::ctrl)] = true;
                break;
            case SDLK_ESCAPE:
                key_states[int(Key::escape)] = true;
                break;
            case SDLK_LALT:
                key_states[int(Key::alt)] = true;
                break;
            case SDLK_RALT:
                key_states[int(Key::alt)] = true;
                break;
            case SDLK_TAB:
                key_states[int(Key::tab)] = true;
                break;
            case SDLK_CAPSLOCK:
                key_states[int(Key::caps_lock)] = true;
                break;
            }
        }
        else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
            case SDLK_q:
                key_states[int(Key::q)] = false;
                break;
            case SDLK_w:
                key_states[int(Key::w)] = false;
                break;
            case SDLK_e:
                key_states[int(Key::e)] = false;
                break;
            case SDLK_r:
                key_states[int(Key::r)] = false;
                break;
            case SDLK_t:
                key_states[int(Key::t)] = false;
                break;
            case SDLK_y:
                key_states[int(Key::y)] = false;
                break;
            case SDLK_u:
                key_states[int(Key::u)] = false;
                break;
            case SDLK_i:
                key_states[int(Key::i)] = false;
                break;
            case SDLK_o:
                key_states[int(Key::o)] = false;
                break;
            case SDLK_p:
                key_states[int(Key::p)] = false;
                break;
            case SDLK_a:
                key_states[int(Key::a)] = false;
                break;
            case SDLK_s:
                key_states[int(Key::s)] = false;
                break;
            case SDLK_d:
                key_states[int(Key::d)] = false;
                break;
            case SDLK_f:
                key_states[int(Key::f)] = false;
                break;
            case SDLK_g:
                key_states[int(Key::g)] = false;
                break;
            case SDLK_h:
                key_states[int(Key::h)] = false;
                break;
            case SDLK_j:
                key_states[int(Key::j)] = false;
                break;
            case SDLK_k:
                key_states[int(Key::k)] = false;
                break;
            case SDLK_l:
                key_states[int(Key::l)] = false;
                break;
            case SDLK_z:
                key_states[int(Key::z)] = false;
                break;
            case SDLK_x:
                key_states[int(Key::x)] = false;
                break;
            case SDLK_c:
                key_states[int(Key::c)] = false;
                break;
            case SDLK_v:
                key_states[int(Key::v)] = false;
                break;
            case SDLK_b:
                key_states[int(Key::b)] = false;
                break;
            case SDLK_n:
                key_states[int(Key::n)] = false;
                break;
            case SDLK_m:
                key_states[int(Key::m)] = false;
                break;
            case SDLK_LSHIFT:
                key_states[int(Key::shift)] = false;
                break;
            case SDLK_RSHIFT:
                key_states[int(Key::shift)] = false;
                break;
            case SDLK_LCTRL:
                key_states[int(Key::ctrl)] = false;
                break;
            case SDLK_RCTRL:
                key_states[int(Key::ctrl)] = false;
                break;
            case SDLK_ESCAPE:
                key_states[int(Key::escape)] = false;
                break;
            case SDLK_LALT:
                key_states[int(Key::alt)] = false;
                break;
            case SDLK_RALT:
                key_states[int(Key::alt)] = false;
                break;
            case SDLK_TAB:
                key_states[int(Key::tab)] = false;
                break;
            case SDLK_CAPSLOCK:
                key_states[int(Key::caps_lock)] = false;
                break;
            }
        }
        else if (e.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_LEFT))) {
                mouse_state.button_state[int(Mouse_button::left_click)] = true;
            }
            else if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_RIGHT))) {
                mouse_state.button_state[int(Mouse_button::left_click)] = true;
            }
            else if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_MIDDLE))) {
                mouse_state.button_state[int(Mouse_button::middle_click)] =
                    true;
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP) {
            if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_LEFT))) {
                mouse_state.button_state[int(Mouse_button::left_click)] = false;
            }
            else if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_RIGHT))) {
                mouse_state.button_state[int(Mouse_button::left_click)] = false;
            }
            else if ((SDL_GetMouseState(&mouse_state.x, &mouse_state.y) &
                SDL_BUTTON(SDL_BUTTON_MIDDLE))) {
                    mouse_state.button_state[int(Mouse_button::middle_click)] =
                        false;
            }
        }
    }
}
