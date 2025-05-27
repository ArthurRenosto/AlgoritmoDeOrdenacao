#include <stdio.h>

// ---------- Funções auxiliares ---------- //

// Merge crescente
void merge_cres(int arr[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[fim - inicio + 1];

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
}

// Merge decrescente
void merge_desc(int arr[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[fim - inicio + 1];

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

