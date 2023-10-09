#include "Input.h"
#include "GameHeader.h"
#include <SDL2/SDL.h>
#include <memory>

Input::Input() {
  memset(this, 0, sizeof(Input));
}

void Input::EndFrame() {
  memset(key_press, 0, sizeof(key_press));
  memset(mouse_button_press, 0, sizeof(mouse_button_press));
  mouse_dx = mouse_dx * GH_MOUSE_SMOOTH + mouse_ddx * (1.0f - GH_MOUSE_SMOOTH);
  mouse_dy = mouse_dy * GH_MOUSE_SMOOTH + mouse_ddy * (1.0f - GH_MOUSE_SMOOTH);
  mouse_ddx = 0.0f;
  mouse_ddy = 0.0f;
}

void Input::UpdateRaw(unsigned state,int mouse_x,int mouse_y) {
  mouse_dx = (float)mouse_x;
  mouse_dy = (float)mouse_y;
  mouse_ddx += mouse_dx;
  mouse_ddy += mouse_dy;
  if (state & SDL_BUTTON_LMASK) {
    mouse_button[0] = true;
    mouse_button_press[0] = true;
  }
  if (state & SDL_BUTTON_MMASK) {
    mouse_button[1] = true;
    mouse_button_press[1] = true;
  }
  if (state & SDL_BUTTON_RMASK) {
    mouse_button[2] = true;
    mouse_button_press[2] = true;
  }
}
