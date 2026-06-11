#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /*int array[3][3] = {{1,2,3},
                       {4,5,6},
                       {7,8,9}};*/

    //This is what Im going to translate in 2D array

    int **array = malloc(3*sizeof(int*));

    int *array0 = malloc(3*sizeof(int));
    int *array1 = malloc(3*sizeof(int));
    int *array2 = malloc(3*sizeof(int));

    /*now to store this we need a double pointer, so go 
    back and declare*/

    //now,
    array[0] = array0;
    array[1] = array1;
    array[2] = array2;

    return 0;
}
