/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float get_cpu_clock_speed()
{
	FILE *fp;
	char buffer[10000];
	size_t bytes_read;
	char *match;
	float clock_speed;

	fp = fopen("/proc/cpuinfo", "r");
	bytes_read = fread(buffer, 1, sizeof(buffer), fp);
	fclose(fp);

	if(bytes_read == 0 || bytes_read == sizeof(buffer))
		return 0;

	buffer[bytes_read] = '\0';

	match = strstr(buffer, "cpu MHz");

	if(match == NULL)
		return 0;

	sscanf(match, "cpu MHz : %f", &clock_speed);
	return clock_speed;
}

int main(void) {
	printf("CPU clock speed: %4.0f MHz\n", get_cpu_clock_speed());
	return EXIT_SUCCESS;
}
