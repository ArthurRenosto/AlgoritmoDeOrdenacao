#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion_sort.h"

void random_generator(){
    int i, j;
    int linhas = 4;
    int colunas = 10;
    int number[4][10];

    srand(time(NULL));

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++) {
            number[i][j] = rand() % 1000;
        }
    }

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++) {
            printf("%4d ", number[i][j]);
        }
        printf("\n");
    }
}
      for (i = 0; i < linhas; i++) {
        insertion_sort(number[i], colunas);
    }

    printf("Matriz com linhas ordenadas: \n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", number[i][j]);
        }
        printf("\n");
    }

int main(){
    random_generator();
return 0;
}
