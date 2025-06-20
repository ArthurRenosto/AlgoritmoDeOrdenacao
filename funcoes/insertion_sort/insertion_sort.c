#include "insertion_sort.h"  // Importa os protótipos das funções de ordenação por inserção
#include <stdio.h>           // Biblioteca padrão de entrada e saída (ex: printf)
#include <stdlib.h>          // Biblioteca para uso de malloc e free
#include "../lista_encadeada.h" // Biblioteca da lista encadeada

// Função que implementa o algoritmo de Insertion Sort em ordem crescente
void insertion_sort_cres(int vetor[], int tamanho) {
    // Alterado: uso de ponteiro para vetor auxiliar dinâmico
    int *aux = (int*)malloc(tamanho * sizeof(int));
    int i, j, chave;
    printf("\n**Insertion Sort Crescente**\n\n");

    for (i = 0; i < tamanho; i++) {
        aux[i] = vetor[i];
    }

    // Começa a partir do segundo elemento (índice 1)
    for (i = 1; i < tamanho; i++) {
        chave = aux[i];  // Salva o valor atual a ser posicionado
        j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && aux[j] > chave) {
            aux[j + 1] = aux[j];
            j--;
        }

        // Insere a chave na posição correta
        aux[j + 1] = chave;

        // Exibe o vetor após cada passo do algoritmo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", aux[k]);
        }
        printf("\n");
    }
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
    // Alterado: liberação da memória dinâmica
    free(aux);
}

// Função que implementa o algoritmo de Insertion Sort em ordem decrescente
void insertion_sort_desc(int vetor[], int tamanho) {
    // Alterado: uso de ponteiro para vetor auxiliar dinâmico
    int *aux = (int*)malloc(tamanho * sizeof(int));
    int i, j, chave;
    printf("\n**Insertion Sort Decrescente**\n\n");

    for (i = 0; i < tamanho; i++) {
        aux[i] = vetor[i];
    }

    // Começa a partir do segundo elemento (índice 1)
    for (i = 1; i < tamanho; i++) {
        chave = aux[i];  // Salva o valor atual a ser posicionado
        j = i - 1;

        // Move os elementos menores que a chave uma posição à frente
        while (j >= 0 && aux[j] < chave) {
            aux[j + 1] = aux[j];
            j--;
        }

        // Insere a chave na posição correta
        aux[j + 1] = chave;

        // Exibe o vetor após cada passo do algoritmo
        printf("Passo %d: ", i);
        for (int k = 0; k < tamanho; k++) {
            printf("%d ", aux[k]);
        }
        printf("\n");
    }
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
    // Alterado: liberação da memória dinâmica
    free(aux);
}

// Função que implementa o algoritmo de Insertion Sort em ordem crescente usando lista encadeada
void insertion_sort_cres_lista(int vetor[], int tamanho) {
    Node* sorted = NULL;
    Node* head = vetor_para_lista(vetor, tamanho, 0); // 0 = inserir no início
    Node* atual = head;
    while (atual != NULL) {
        Node* next = atual->prox;
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
    lista_para_vetor(sorted, vetor, tamanho);
    liberar_lista(sorted);
}

// Função que implementa o algoritmo de Insertion Sort em ordem decrescente usando lista encadeada
void insertion_sort_desc_lista(int vetor[], int tamanho) {
    Node* sorted = NULL;
    Node* head = vetor_para_lista(vetor, tamanho, 0); // 0 = inserir no início
    Node* atual = head;
    while (atual != NULL) {
        Node* next = atual->prox;
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
