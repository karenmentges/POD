#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i;
    int num2[1000];

    srand(time(NULL));

    for(i = 0; i < 1000; i++)
        num2[i] = rand() % 10000;

    printf("\n");
    for(i = 0; i < 1000; i++)
        printf("%d ", num2[i]);
    printf("\n");

    return 0;
}