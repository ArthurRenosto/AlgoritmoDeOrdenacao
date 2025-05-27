#include <stdio.h>      // Biblioteca padrão de entrada e saída (ex: printf, scanf)
#include <stdlib.h>     // Biblioteca padrão (ex: rand, malloc, free)
#include <time.h>       // Biblioteca para lidar com tempo (ex: time, srand)

#include "funcoes/insertion_sort/insertion_sort.h"  // Importa os protótipos do insertion sort
#include "funcoes/merge_sort/merge_sort.h"          // Importa os protótipos do merge sort

// Função que gera números aleatórios e preenche uma matriz
void random_generator(int linhas, int colunas, int number[linhas][colunas]) {
    int i, j;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios com base no tempo atual

    // Preenche a matriz com números aleatórios de 0 a 999
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++) {
            number[i][j] = rand() % 1000;
        }
    }

    // Imprime a matriz gerada
    for (i = 0; i < linhas; i++){
        printf(" %d -", i+1);
        for (j = 0; j < colunas; j++) {
            printf("%4d ", number[i][j]);  // "%4d" alinha os números em 4 espaços
        }
        printf("\n\n");
    }
}

int main(){
    int op = 0;                           // Variável que guarda a opção do menu
    int i, j;                             // Contadores para loops
    int linhas = 2;                       // Número de linhas da matriz
    int colunas = 10;                     // Número de colunas da matriz
    int number[linhas][colunas];          // Matriz de inteiros

    do {
        // Menu de seleção de método de ordenação
        printf("\n");
        printf("Qual metodo de ordenacao gostaria de usar ?\n");
        printf("0 - Sair do Programa.\n");
        printf("1 - Insertion Sort Crescente.\n");
        printf("2 - Insertion Sort Decrescente.\n");
        printf("3 - Merge Sort Crescente.\n");
        printf("4 - Merge Sort Decrescente.\n");
        scanf("%d", &op);  // Lê a opção do usuário

        // Gera e imprime a matriz aleatória se a opção for válida
        if (op >= 1 && op <= 4) {
            printf("\n\n");
            printf("Array inicial: \n\n");
            printf("-------------------------------------------------\n\n");
            random_generator(linhas, colunas, number);  // Gera os números
            printf("-------------------------------------------------\n");
        }

        // Executa o método de ordenação conforme a escolha do usuário
        if (op == 1) {
            for (i = 0; i < linhas; i++) {
                insertion_sort_cres(number[i], colunas);  // Ordena linha por linha em ordem crescente
            }
        } else if (op == 2) {
            for (i = 0; i < linhas; i++) {
                insertion_sort_desc(number[i], colunas);  // Ordem decrescente com insertion sort
            }
        } else if (op == 3) {
            for (i = 0; i < linhas; i++) {
                merge_sort_cres(number[i], colunas);      // Ordem crescente com merge sort
            }
        } else if (op == 4) {
            for (i = 0; i < linhas; i++) {
                merge_sort_desc(number[i], colunas);      // Ordem decrescente com merge sort
            }
        } else if (op == 0) {
            printf("Saindo do programa . . .\n");          // Finaliza o programa
        } else {
            printf("Por favor digite uma opcao valida!\n"); // Caso o usuário digite algo fora do menu
        }

        // Exibe a matriz ordenada (se alguma ordenação foi feita)
        if (op >= 1 && op <= 4) {
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

    } while (op != 0);  // Repete até que o usuário escolha sair

    return 0;
}
