#define MIN_SIZE 4
#define DIM_BUFFER 1024
#define MAGIC_NUMBER 5 // "test" number of chars + 1 char for \0 

void print_strvect(char **vector, int n);
char** file_row_list(FILE *f, char **vettore, int *n);


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
		vector[(*n)] = malloc(sizeof(char)*strlen(str));
		strcpy(vector[(*n)], str);
		printf("%ld - %ld - %ld - %ld\n", strlen(str), strlen(vector[(*n)]), sizeof(str), sizeof(vector[(*n)]));
		(*n)++;
		//vector[(*n)++] = strdup(str);
		if((*n) >= size) {
			size += MIN_SIZE;
			vector = realloc(vector, sizeof(vector)*size);
		}
	}
	
	return vector;
}


