#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int tamanho = 10; // tamanho do array
    int numeros[40][40];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o array com números aleatórios de 0 a 99
    for (i = 0; i < tamanho; i++) {
        numeros[i] = rand() % 100; // números de 0 a 99
    }

    // Exibe o array
    printf("Array de numeros aleatorios:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
