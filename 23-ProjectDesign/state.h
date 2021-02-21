#ifndef _STATE_H
#define _STATE_H

#include <stdint.h>

typedef struct state{
	void(*State)(void);
}State;

void State_Change(State current, State next);

#endif
