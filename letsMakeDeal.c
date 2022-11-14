#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("*********************\n");
    printf("* Let's make a deal  \n*");
    printf("*********************\n\n");

    int chute;
    int portaPremiada;
    int portaErrada;
    int trocar = 0;

    printf("Atrás de uma dessas portas há uma barra de ouro, \n atrás das outras duas, duas lixeiras\n\n");

    srand(time(0));
    portaPremiada = (rand()%3) + 1;
    printf("Porta premiada: %d\n\n", portaPremiada); //teste

    printf("Escolha a porta (1, 2 ou 3):");
    scanf("%d", &chute);

    if (portaPremiada == chute){
        printf("Parabéns, você acertou!\n");
    } 
    else {
        printf("Ops, você errou, tente novamente.\n");
    }
}