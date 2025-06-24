#include "insertion_sort.h"  // Importa os protótipos das funções de ordenação por inserção
#include <stdio.h>           // Biblioteca padrão de entrada e saída (ex: printf)
#include <stdlib.h>          // Biblioteca para uso de malloc e free
#include "../lista_encadeada.h" // Biblioteca da lista encadeada

// Função que implementa o algoritmo de Insertion Sort em ordem crescente
// Recebe um vetor de inteiros e seu tamanho, ordena em ordem crescente
void insertion_sort_cres(int vetor[], int tamanho) {
    int *aux = (int*)malloc(tamanho * sizeof(int)); // Vetor auxiliar dinâmico
    int i, j, chave;
    printf("\n**Insertion Sort Crescente**\n\n");

    // Copia o vetor original para o auxiliar
    for (i = 0; i < tamanho; i++) {
        aux[i] = vetor[i];
    }

    // Algoritmo de ordenação por inserção (crescente)
    for (i = 1; i < tamanho; i++) {
        chave = aux[i];  // Elemento a ser inserido
        j = i - 1;
        // Move elementos maiores para frente
        while (j >= 0 && aux[j] > chave) {
            aux[j + 1] = aux[j];
            j--;
        }
        aux[j + 1] = chave; // Insere a chave na posição correta
        // Exibe o vetor após cada passo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", aux[k]);
        }
        printf("\n");
    }
    // Copia o resultado para o vetor original
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
    free(aux); // Libera memória
}

// Função que implementa o algoritmo de Insertion Sort em ordem decrescente
// Recebe um vetor de inteiros e seu tamanho, ordena em ordem decrescente
void insertion_sort_desc(int vetor[], int tamanho) {
    int *aux = (int*)malloc(tamanho * sizeof(int)); // Vetor auxiliar dinâmico
    int i, j, chave;
    printf("\n**Insertion Sort Decrescente**\n\n");

    // Copia o vetor original para o auxiliar
    for (i = 0; i < tamanho; i++) {
        aux[i] = vetor[i];
    }

    // Algoritmo de ordenação por inserção (decrescente)
    for (i = 1; i < tamanho; i++) {
        chave = aux[i];
        j = i - 1;
        // Move elementos menores para frente
        while (j >= 0 && aux[j] < chave) {
            aux[j + 1] = aux[j];
            j--;
        }
        aux[j + 1] = chave;
        // Exibe o vetor após cada passo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", aux[k]);
        }
        printf("\n");
    }
    // Copia o resultado para o vetor original
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
    free(aux); // Libera memória
}

// Função que implementa o Insertion Sort crescente usando lista encadeada
// Converte o vetor em lista, ordena inserindo em ordem, converte de volta
void insertion_sort_cres_lista(int vetor[], int tamanho) {
    Node* sorted = NULL; // Lista ordenada
    Node* head = vetor_para_lista(vetor, tamanho, 0); // Converte vetor para lista
    Node* atual = head;
    while (atual != NULL) {
        Node* next = atual->prox;
        // Insere ordenado (crescente)
        if (sorted == NULL || atual->valor < sorted->valor) {
            atual->prox = sorted;
            sorted = atual;
        } else {
            Node* temp = sorted;
            while (temp->prox != NULL && temp->prox->valor < atual->valor) {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = next;
    }
    lista_para_vetor(sorted, vetor, tamanho); // Converte lista para vetor
    liberar_lista(sorted); // Libera memória
}

// Função que implementa o Insertion Sort decrescente usando lista encadeada
// Converte o vetor em lista, ordena inserindo em ordem decrescente, converte de volta
void insertion_sort_desc_lista(int vetor[], int tamanho) {
    Node* sorted = NULL;
    Node* head = vetor_para_lista(vetor, tamanho, 0);
    Node* atual = head;
    while (atual != NULL) {
        Node* next = atual->prox;
        // Insere ordenado (decrescente)
        if (sorted == NULL || atual->valor > sorted->valor) {
            atual->prox = sorted;
            sorted = atual;
        } else {
            Node* temp = sorted;
            while (temp->prox != NULL && temp->prox->valor > atual->valor) {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = next;
    }
    lista_para_vetor(sorted, vetor, tamanho);
    liberar_lista(sorted);
}
