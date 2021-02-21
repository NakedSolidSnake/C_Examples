#include <stdio.h>
#include <stdlib.h>

typedef void (*State)(void);

void InitialState(void);
void State2(void);
void State3(void);
void EndStat(void);

State state = InitialState;

int main(int argc, char const *argv[])
{
	state();
	return 0;
}

void InitialState(void)
{
	char a;
	printf("InitialState\n");
	printf("Press a to jump next state\n");
	scanf(" %c", &a);
	if(a == 'a'){
		state = State2;		
	}

	else{
		state = InitialState;
	}
	state();

}

void State2(void)
{
	char a;
	printf("State 2\n");
	printf("Press a to jump next state\n");
	scanf(" %c", &a);
	if(a == 'a'){
		state = State3;		
	}

	else{
		state = InitialState;
	}
	state();	
}

void State3(void)
{
	char a;
	printf("State 3\n");
	printf("Press a to jump next state\n");
	scanf(" %c", &a);
	if(a == 'a'){
		state = EndStat;		
	}

	else{
		state = InitialState;
	}
	state();		
}

void EndStat(void)
{
	char a;
	printf("End State\n");
	printf("Press any button to finish \'a\' to finish or other to continue\n");
	 scanf(" %c", &a);
	if(a == 'a'){
		printf("END!!!\n");
		exit(0);

	}
	else 
		state = InitialState;
	state();
}