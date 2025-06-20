#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Ordena um vetor em ordem crescente usando Merge Sort
void merge_sort_cres(int vetor[], int tamanho);

// Ordena um vetor em ordem decrescente usando Merge Sort
void merge_sort_desc(int vetor[], int tamanho);

// Protótipos para merge sort usando lista encadeada
typedef struct Node Node;
Node* merge_sort_lista_cres(Node* head);
Node* merge_sort_lista_desc(Node* head);
void merge_sort_cres_lista(int vetor[], int tamanho);
void merge_sort_desc_lista(int vetor[], int tamanho);

#endif