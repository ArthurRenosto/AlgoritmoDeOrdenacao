#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para lista encadeada
typedef struct Node {
    int valor;           // Valor armazenado no nó
    struct Node *prox;   // Ponteiro para o próximo nó
} Node;

// Insere um novo nó no início da lista. Retorna o novo início.
Node* inserir_inicio(Node* head, int valor);
// Insere um novo nó no final da lista. Retorna o início.
Node* inserir_fim(Node* head, int valor);
// Converte um vetor em lista encadeada. Se fim=1, insere no final; se fim=0, insere no início.
Node* vetor_para_lista(int vetor[], int tamanho, int fim);
// Copia os valores da lista encadeada para um vetor.
void lista_para_vetor(Node* head, int vetor[], int tamanho);
// Libera toda a memória alocada para a lista encadeada.
void liberar_lista(Node* head);

#endif // LISTA_ENCADEADA_H
