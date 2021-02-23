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
#include <linux/kernel.h>
#include <linux/sys.h>
#include <sys/sysinfo.h>

int main(void) {
	const long minute = 60;
	const long hour = minute * 60;
	const long day = hour * 24;
	const double megabyte = 1024 * 1024;

	struct sysinfo si;
	sysinfo(&si);

	printf ("system uptime : %ld days, %ld:%02ld:%02ld\n",si.uptime / day, (si.uptime % day) / hour,
	(si.uptime % hour) / minute, si.uptime % minute);
	printf ("total RAM	: %5.1f MB\n", si.totalram / megabyte);
	printf ("free RAM	: %5.1f MB\n", si.freeram / megabyte);
	printf ("process count : %d\n", si.procs);
	return EXIT_SUCCESS;
}
