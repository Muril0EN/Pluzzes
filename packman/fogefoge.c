#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char mapa[5][10+1];// a declaração de 10+1 pq a string termina com \0; 

    FILE* arquivo; //nome do arquivo
    arquivo = fopen("mapa.txt", "r");
    if(arquivo == 0) {
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        fscanf(arquivo, "%s", mapa[i]);//lê a linha inteira e passa para o mapa a cada loop
    }

    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);//imprime mapa
    }

    fclose(arquivo);
    
}