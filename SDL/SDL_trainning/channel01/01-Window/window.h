#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>

typedef struct window_t window_t;

window_t *window_constructor(const char *title, int width, int height);
void window_destructor(window_t *window);

#endif /* WINDOW_H */
