/**
 * Implementation of arbitrary length LFSR.
 * Input: binary sequence describing the LFSR.
 * Output: binary sequence generated by the LFSR in one period.
 */

/**
 * Steps:
 * 1) Get the binary sequence
 * 2) 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "lfsr.h"

#define MAX_OUT_LEN 10000

void usage(char *name) {
	printf("Usage: %s BINARY_SEQ_DESCRIPTION BINARY_INITIAL_STATE [HOW_MANY_DIGITS]\n", name);
	printf("Length of BINARY_SEQ_DESCRIPTION must be equal to length of BINARY_INITIAL_STATE\n");
	exit(1);
}

int main(int argc, char *argv[]) {
	char lfsr_output[MAX_OUT_LEN];
	int lfsr_output_int[MAX_OUT_LEN];
	int lfsr_desc[MAX_OUT_LEN], lfsr_init_state[MAX_OUT_LEN];
	int len;
	int howmany;
	LFSR lfsr;
	int i;

	if (argc < 3 || strlen(argv[1]) != strlen(argv[2])) {
		usage(argv[0]);
	}

	len = strlen(argv[1]);
	
	for (i = 0; i < len; i++) {
		lfsr_desc[i] = c2b(argv[1][i]);
	}
	for (i = 0; i < len; i++) {
		lfsr_init_state[i] = c2b(argv[2][i]);
	}


	memcpy(lfsr.descriptor, lfsr_desc, len * sizeof(int));
	memcpy(lfsr.initial_state, lfsr_init_state, len * sizeof(int));
	lfsr.len = len;
	howmany = (argc <= 3)? 0 : atoi(argv[3]);

	get_lfsr_output(&lfsr, lfsr_output_int, howmany);

	for (i = 0; i < howmany; i++) {
		lfsr_output[i] = (lfsr_output_int[i] == 0)? '0' : '1';
	}
	lfsr_output[i] = '\0';
	printf("%s\n", lfsr_output);

	return 0;
}