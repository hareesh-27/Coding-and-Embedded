#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int **array = malloc(n * sizeof(int*));

    // allocate rows
    for(int i = 0; i < n; i++) {
        array[i] = malloc(n * sizeof(int));
    }

    // initialize 1 → 9
    int val = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            array[i][j] = val++;
        }
    }

    // print matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
