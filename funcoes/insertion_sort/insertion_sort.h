#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

// Protótipos das funções de ordenação por inserção (Insertion Sort)
// Ordena um vetor em ordem crescente usando Insertion Sort
void insertion_sort_cres(int vetor[], int tamanho);

// Ordena um vetor em ordem decrescente usando Insertion Sort
void insertion_sort_desc(int vetor[], int tamanho);

// Protótipos para as versões com lista encadeada
// Ordena um vetor em ordem crescente usando Insertion Sort com lista encadeada
void insertion_sort_cres_lista(int vetor[], int tamanho);
// Ordena um vetor em ordem decrescente usando Insertion Sort com lista encadeada
void insertion_sort_desc_lista(int vetor[], int tamanho);

#endif //INSERTION_SORT_H
