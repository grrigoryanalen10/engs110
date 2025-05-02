#include "array.h"

#include <stdio.h>
#include <stdlib.h>

int main(int c, char* v[])
{
	FILE* f = 0;
	int k = 0;
        if (c != 2) {
                printf("Run with file: %s <file>\n", v[0]);
                return EXIT_FAILURE;
        }
        f = fopen(v[1], "r");
        if (f == 0) {
                printf("Failed to open %s\n", v[1]);
                return EXIT_FAILURE;
        }
	struct array* n = array_create();
        while (fscanf(f, "%d", &k) == 1) {
                printf("a\n");
		array_push_back(n, k);
        }
	array_print(n);
        fclose(f);
        return 0;
}
