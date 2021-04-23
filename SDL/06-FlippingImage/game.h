#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
void render(void);
void update(void);
void handleEvents(void);
void clean(void);
bool running(void);

#endif /* GAME_H_ */
