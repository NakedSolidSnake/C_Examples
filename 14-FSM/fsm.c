/*
 * fsm.c
 *
 *  Created on: 14 de fev de 2019
 *      Author: solid
 */


#include "fsm.h"
#include <stdio.h>
#include <stdbool.h>

static void InitMe(void);
static void SetMeUp(void);
static void MyActions(void);
static void DoNothing(void);

static State state;

void Start(void)
{
	bool keep = true;
	state = Initialize;
	while(keep)
	{
		switch (state) {
		case Initialize:
			InitMe();
			break;

		case Setup:
			SetMeUp();
			break;

		case Actions:
			MyActions();
			break;

		case Idle:
			DoNothing();
			keep = false;
			break;
		default:
			break;
		}
	}
}


static void InitMe(void)
{
	printf("This is the InitMe function\n");
	state = Setup;
}

static void SetMeUp(void)
{
	printf("This is the SetMeUp function\n");
	state = Actions;
}

static void MyActions(void)
{
	printf("This is the Actions function\n");
	state = Idle;
}

static void DoNothing(void)
{
	printf("This is the DoNothing function\n");
}
