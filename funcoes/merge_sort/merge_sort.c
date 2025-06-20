#include <stdio.h>
#include <stdlib.h> // Incluído para uso do malloc e free
#include "../lista_encadeada.h"

// Protótipos das funções de merge de listas encadeadas
Node* merge_lista_cres(Node* l1, Node* l2);
Node* merge_lista_desc(Node* l1, Node* l2);

// Protótipos das funções de merge sort para lista encadeada
static Node* merge_sort_lista_cres(Node* head);
static Node* merge_sort_lista_desc(Node* head);

// ---------- Funções auxiliares ---------- //

// Merge crescente
void merge_cres(int arr[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    // Alterado: Alocação dinâmica do array temporário para reforçar uso de ponteiros e memória dinâmica
    int *temp = (int *)malloc((fim - inicio + 1) * sizeof(int));

    printf("Merge crescente: [%d..%d], meio=%d\n", inicio, fim, meio);
    printf("  Antes do merge: ");
    for (int x = inicio; x <= fim; x++) printf("%d ", arr[x]);
    printf("\n");

    while (i <= meio && j <= fim) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= fim) {
        temp[k++] = arr[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        arr[i] = temp[k];
    }

    printf("  Depois do merge: ");
    for (int x = inicio; x <= fim; x++) printf("%d ", arr[x]);
    printf("\n\n");

    // Alterado: Liberação da memória alocada dinamicamente
    free(temp);
}

// Merge decrescente
void merge_desc(int arr[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    // Alterado: Alocação dinâmica do array temporário para reforçar uso de ponteiros e memória dinâmica
    int *temp = (int *)malloc((fim - inicio + 1) * sizeof(int));

    printf("Merge decrescente: [%d..%d], meio=%d\n", inicio, fim, meio);
    printf("  Antes do merge: ");
    for (int x = inicio; x <= fim; x++) printf("%d ", arr[x]);
    printf("\n");

    while (i <= meio && j <= fim) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= fim) {
        temp[k++] = arr[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        arr[i] = temp[k];
    }

    printf("  Depois do merge: ");
    for (int x = inicio; x <= fim; x++) printf("%d ", arr[x]);
    printf("\n\n");

    // Alterado: Liberação da memória alocada dinamicamente
    free(temp);
}

// ---------- Funções recursivas ---------- //

void merge_sort_rec_cres(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        printf("Dividir crescente: [%d..%d], meio=%d\n", inicio, fim, meio);
        merge_sort_rec_cres(arr, inicio, meio);
        merge_sort_rec_cres(arr, meio + 1, fim);
        merge_cres(arr, inicio, meio, fim);
    }
}

void merge_sort_rec_desc(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        printf("Dividir decrescente: [%d..%d], meio=%d\n", inicio, fim, meio);
        merge_sort_rec_desc(arr, inicio, meio);
        merge_sort_rec_desc(arr, meio + 1, fim);
        merge_desc(arr, inicio, meio, fim);
    }
}

// ---------- Interfaces principais ---------- //

void merge_sort_cres(int arr[], int tamanho) {
    merge_sort_rec_cres(arr, 0, tamanho - 1);
}

void merge_sort_desc(int arr[], int tamanho) {
    merge_sort_rec_desc(arr, 0, tamanho - 1);
}

// ---------- Impressão ---------- //

void imprimir(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------- Funções para Lista Encadeada ---------- //

void merge_sort_cres_lista(int vetor[], int tamanho) {
    Node* head = vetor_para_lista(vetor, tamanho, 1); // 1 = inserir no fim
    head = merge_sort_lista_cres(head);
    lista_para_vetor(head, vetor, tamanho);
    liberar_lista(head);
}

void merge_sort_desc_lista(int vetor[], int tamanho) {
    Node* head = vetor_para_lista(vetor, tamanho, 1); // 1 = inserir no fim
    head = merge_sort_lista_desc(head);
    lista_para_vetor(head, vetor, tamanho);
    liberar_lista(head);
}

// Implementação das funções de merge sort para lista encadeada
static Node* merge_sort_lista_cres(Node* head) {
    if (!head || !head->prox) return head;
    Node *slow = head, *fast = head->prox;
    while (fast && fast->prox) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }
    Node* mid = slow->prox;
    slow->prox = NULL;
    Node* left = merge_sort_lista_cres(head);
    Node* right = merge_sort_lista_cres(mid);
    return merge_lista_cres(left, right);
}

static Node* merge_sort_lista_desc(Node* head) {
    if (!head || !head->prox) return head;
    Node *slow = head, *fast = head->prox;
    while (fast && fast->prox) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }
    Node* mid = slow->prox;
    slow->prox = NULL;
    Node* left = merge_sort_lista_desc(head);
    Node* right = merge_sort_lista_desc(mid);
    return merge_lista_desc(left, right);
}

// Implementação das funções de merge de listas encadeadas
Node* merge_lista_cres(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.prox = NULL;
    while (l1 && l2) {
        if (l1->valor < l2->valor) {
            tail->prox = l1;
            l1 = l1->prox;
        } else {
            tail->prox = l2;
            l2 = l2->prox;
        }
        tail = tail->prox;
    }
    tail->prox = (l1) ? l1 : l2;
    return dummy.prox;
}

Node* merge_lista_desc(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.prox = NULL;
    while (l1 && l2) {
        if (l1->valor > l2->valor) {
            tail->prox = l1;
            l1 = l1->prox;
        } else {
            tail->prox = l2;
            l2 = l2->prox;
        }
        tail = tail->prox;
    }
    tail->prox = (l1) ? l1 : l2;
    return dummy.prox;
}
