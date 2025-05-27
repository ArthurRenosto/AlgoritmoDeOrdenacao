#include "insertion_sort.h"  // Importa os protótipos das funções de ordenação por inserção
#include <stdio.h>           // Biblioteca padrão de entrada e saída (ex: printf)

// Função que implementa o algoritmo de Insertion Sort em ordem crescente
void insertion_sort_cres(int vetor[], int tamanho) {
    int i, j, chave;
    printf("\n**Insertion Sort Crescente**\n\n");

    // Começa a partir do segundo elemento (índice 1)
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];  // Salva o valor atual a ser posicionado
        j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        // Insere a chave na posição correta
        vetor[j + 1] = chave;

        // Exibe o vetor após cada passo do algoritmo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
    }
}

// Função que implementa o algoritmo de Insertion Sort em ordem decrescente
void insertion_sort_desc(int vetor[], int tamanho) {
    int i, j, chave;
    printf("\n**Insertion Sort Decrescente**\n\n");

    // Começa a partir do segundo elemento (índice 1)
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];  // Salva o valor atual a ser posicionado
        j = i - 1;

        // Move os elementos menores que a chave uma posição à frente
        while (j >= 0 && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        // Insere a chave na posição correta
        vetor[j + 1] = chave;

        // Exibe o vetor após cada passo do algoritmo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
    }
}