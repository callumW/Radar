#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include "Graphics.h"

namespace howling_pass {

    constexpr int num_of_keys = 32;
    constexpr int num_of_mouse_buttons = 3;

enum class Key {
    q,
    w,
    e,
    r,
    t,
    y,
    u,
    i,
    o,
    p,
    a,
    s,
    d,
    f,
    g,
    h,
    j,
    k,
    l,
    z,
    x,
    c,
    v,
    b,
    n,
    m,
    shift,
    ctrl,
    escape,
    alt,
    tab,
    caps_lock
};

enum class Mouse_button {
    left_click,
    right_click,
    middle_click
};

struct Mouse_state {
    int x = 0, y = 0;
    bool button_state[num_of_mouse_buttons];
    Mouse_state()
    {
        for (int i=0; i<num_of_mouse_buttons; i++) {
            button_state[i] = false;
        }
    }
};

class Input_handler {
public:

    Input_handler();
    ~Input_handler();

    /**
     * Update the key and mouse States
     */
    void update();

    /**
     * Return the state of the specified key.
     * \param k They Key enum of the key you want to check.
     * \return True if key is down, false otherwise
     */
    bool state(Key k) const {return key_states[int(k)];}

    /**
     * Return the x coordinate of the mouse.
     * \return The x coordinate of the mouse on the screen. If the mouse is of
     * screen, then the last x coordinate on screen is returned.
     */
    int mouse_x() const {return mouse_state.x;}

    /**
     * Return the y coordinate of the mouse.
     * \return The y coordinate of the mouse on the screen. If the mouse is of
     * screen, then the last x coordinate on screen is returned.
     */
    int mouse_y() const {return mouse_state.y;}

	bool quit_requested() const { return quit; }

private:
    bool key_states[num_of_keys];
    Mouse_state mouse_state;
    bool quit = false;
};

}

#endif
