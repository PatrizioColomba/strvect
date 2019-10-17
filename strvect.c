#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "strvect.h"

#define MIN_SIZE 	4
#define BUFFER_SIZE 1024

void print_strvect(char **vector, int n) {
	for(int i = 0; i < n; i++) {
		printf("%s", vector[i]);
		char* newline = strchr(vector[i], '\n');
		if(newline) {
			int len = strlen(vector[i]);
			if(newline != &(vector[i][len-1])) puts("");
		} else puts("");
	}
}

char** file_row_list(FILE *f, char **vector, int *n) {
	int size = MIN_SIZE;
	vector = calloc(size, sizeof(vector));
	char str[BUFFER_SIZE];
	(*n) = 0;
	while(fgets(str, BUFFER_SIZE, f)) {
		vector[(*n)++] = strdup(str);
		if((*n) >= size) {
			size += MIN_SIZE;
			vector = realloc(vector, sizeof(vector)*size);
		}
	}
	vector = realloc(vector, sizeof(vector)*(*n));
	
	return vector;
}

void free_strvect(char** vector, int n) {
	for(int i = 0; i < n; i++) {
		free(vector[i]);
	}
	free(vector);
}


char** strvect(int n, ...) {
	char **vector = calloc(n, sizeof(vector));
	va_list args;
    va_start(args, n);

	for(int i = 0; i < n; i++) {
		vector[i] = strdup(va_arg(args, char *));
	}

	va_end(args);

	return vector;
}

