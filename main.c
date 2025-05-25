#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes/insertion_sort/insertion_sort.h"
#include "funcoes/metodoOrdenacao/quick_sort.h"

void random_generator(int linhas, int colunas, int number[linhas][colunas]) {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++) {
            number[i][j] = rand() % 1000;
        };
    };

    for (i = 0; i < linhas; i++){
        printf(" %d -", i+1);
        for (j = 0; j < colunas; j++) {
            printf("%4d ", number[i][j]);
        };
        printf("\n\n");
    };

}

int main(){
    int op = 0;
    int i, j;
    int linhas = 2;
    int colunas = 10;
    int number[linhas][colunas];



    do {
        printf("\n");
        printf("Qual metodo de ordenacao gostaria de usar ?\n");
        printf("0 - Sair do Programa.\n");
        printf("1 - Insertion Sort Crescente.\n");
        printf("2 - Insertion Sort Decrescente.\n");
        scanf("%d", &op);
        if (op>=1 && op<=4) {
            printf("\n\n");
            printf("Array inicial: \n\n");
            printf("-------------------------------------------------\n\n");
            random_generator(linhas, colunas, number);
            printf("-------------------------------------------------\n");
        }

        if (op == 1) {

            for (i = 0; i < linhas; i++) {
                insertion_sort_cres(number[i], colunas);
            }

        }else if(op ==2){

            for (i = 0; i < linhas; i++) {
                insertion_sort_desc(number[i], colunas);
            }

        }else if (op == 0) {

            printf("Saindo do programa . . .");

        }else {

            printf("Por favor digite um opcao valida!");

        }


        if (op>=1 && op<=4) {
            printf("\n\n");
            printf("-------------------------------------------------\n\n");
            printf("Matriz com linhas ordenadas: \n\n");
            for (i = 0; i < linhas; i++) {
                printf(" %d - ", i+1);
                for (j = 0; j < colunas; j++) {
                    printf("%4d ", number[i][j]);
                }
                printf("\n\n");
            }
            printf("-------------------------------------------------\n");
        }


    }while (op!= 0);


return 0;
}
