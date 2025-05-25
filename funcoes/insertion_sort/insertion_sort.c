#include "insertion_sort.h"
#include <stdio.h>

void insertion_sort_cres(int vetor[], int tamanho) {
    int i, j, chave;
    printf("\n**Insertion Sort Crescente**\n\n");
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;

        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
    }
}

void insertion_sort_desc(int vetor[], int tamanho) {
    int i, j, chave;
    printf("\n**Insertion Sort Decrescente**\n\n");
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] < chave) {

            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;

        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
    }
}