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
#include <getopt.h>
#include <stdlib.h>

const char *program_name;

void print_usage(FILE * stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [ inputfile ... ] \n", program_name);
	fprintf(stream,
			" -h  --help				Display this usage information.\n"
			" -o  --output filename		Write output to file.\n"
			" -v --verbose				Print verbose messages.\n");
	exit(exit_code);
}

int main(int argc, char **argv) {
	int next_option;

	const char *const short_options = "ho:v";

	const struct option long_options[] = {
			{"help",    0, NULL, 'h'},
			{"output",  1, NULL, 'o'},
			{"verbose", 0, NULL, 'v'},
			{NULL,      0, NULL,  0 },
	};

	const char *output_filename = NULL;

	int verbose = 0;

	program_name = argv[0];

	do{
		next_option = getopt_long(argc, argv, short_options, long_options, NULL);

		switch (next_option) {
		case 'h':
			print_usage(stdout, 0);
			break;

		case '0':
			output_filename = optarg;
			break;

		case 'v':
			verbose = 1;
			break;

		case '?':
			print_usage(stderr, 1);
			break;

		case -1:
			break;

		default:
			abort();
		}

	}while(next_option != -1);

	if(verbose)
	{
		int i;
		for(i = optind; i < argc; ++i)
		{
			printf("Argument: %s\n", argv[i]);
		}
	}


	return EXIT_SUCCESS;
}
