#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Protótipos das funções de ordenação por Merge Sort
// Ordena um vetor em ordem crescente usando Merge Sort
void merge_sort_cres(int vetor[], int tamanho);
// Ordena um vetor em ordem decrescente usando Merge Sort
void merge_sort_desc(int vetor[], int tamanho);

// Protótipos para merge sort usando lista encadeada
// Estrutura do nó da lista encadeada
typedef struct Node Node;
// Ordena uma lista encadeada em ordem crescente
Node* merge_sort_lista_cres(Node* head);
// Ordena uma lista encadeada em ordem decrescente
Node* merge_sort_lista_desc(Node* head);
// Ordena um vetor em ordem crescente usando merge sort com lista encadeada
void merge_sort_cres_lista(int vetor[], int tamanho);
// Ordena um vetor em ordem decrescente usando merge sort com lista encadeada
void merge_sort_desc_lista(int vetor[], int tamanho);

#endif