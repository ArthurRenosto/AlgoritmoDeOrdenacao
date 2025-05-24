#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_generator(){
    int i, j;
    int tamanho = 10;
    int number[4][10];

    srand(time(NULL));

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < 10;  j++) {
            number[i][j] = rand() % 1000;
        }
    for(i = 0; i < tamanho; i++){
	printf("%d", number[i]);
}
}
}

int main(){
    random_generator();

return 0;
}
