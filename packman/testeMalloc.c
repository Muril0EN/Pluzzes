#include <stdlib.h>
#include <stdio.h>

int main (){
    int** arquivoX = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        arquivoX [i] = malloc(sizeof(int) * 10);
    }

    arquivoX [0] [0] = 10;
    arquivoX [1] [2] = 12;
    printf("Inteiros alocados %d e %d.\n", arquivoX[0][0], arquivoX[1][2]);

    for (int i = 0; i < 5; i++) {
        free(arquivoX[i]);
    }

    free(arquivoX);
    
}