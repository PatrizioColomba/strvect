#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strvect.h"

#define MIN_SIZE 4
#define DIM_BUFFER 1024

void print_strvect(char **vector, int n) {
	for(int i = 0; i < n; i++) {
		printf("%s\n", vector[i]);
	}
}

char** file_row_list(FILE *f, char **vector, int *n) {
	int size = MIN_SIZE;
	vector = calloc(size, sizeof(vector));
	char str[DIM_BUFFER];
	(*n) = 0;
	while(fgets(str, DIM_BUFFER, f)) {
		vector[(*n)++] = strdup(str);
		if((*n) >= size) {
			size += MIN_SIZE;
			vector = realloc(vector, sizeof(vector)*size);
		}
	}
	vector = realloc(vector, sizeof(vector)*(*n));
	
	return vector;
}
