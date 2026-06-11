#include <stdio.h>
#include<stdlib.h>

int main(void) {
    int n;
    printf("Enetr no.of elements :");
    scanf("%d",&n);

    //dynamically creating a 1D array;
    int *array = malloc(n* sizeof(int));

    return 0;
}
