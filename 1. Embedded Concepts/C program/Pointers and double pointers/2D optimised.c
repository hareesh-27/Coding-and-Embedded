#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int **array = malloc(3* sizeof(int*));
    for(int i=0;i<3;i++)
    {
        array[i] = malloc(3* sizeof(int));
    }
    return 0;
}
