#ifndef __STRVECT_H__
#define __STRVECT_H__

void print_strvect(char **vector, int n);
char** file_row_list(FILE *f, char **vettore, int *n);
void free_strvect(char** vector, int n);
char** strvect(int n, ...);

#endif

