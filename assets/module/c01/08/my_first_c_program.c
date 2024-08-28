#include <stdio.h>
#include <stdlib.h>

int main() {
    puts("welcome\n");

    int *array = (int *)calloc(10,sizeof(int));

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    free(array);

    return 0;
}
