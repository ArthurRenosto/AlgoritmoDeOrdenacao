#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* inserir_inicio(Node* head, int valor);
Node* inserir_fim(Node* head, int valor);
Node* vetor_para_lista(int vetor[], int tamanho, int fim);
void lista_para_vetor(Node* head, int vetor[], int tamanho);
void liberar_lista(Node* head);

#endif // LISTA_ENCADEADA_H

