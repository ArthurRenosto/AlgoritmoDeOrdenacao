#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_generator(){
    srand(time(NULL));
    int number = rand() % 1000;
    printf("%d\n", number);
}


    int main(){
    random_generator();
return 0;
}
