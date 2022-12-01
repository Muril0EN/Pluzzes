#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// O compilador do C chama as funções em ordem. Assim, caso se erre na ordenação ocorre um erro
//para evitar esse problema, colaca-se todas as assinaturas em outro arquivo, como headerfile

#include "forca.h"

char palavraSecreta [20];
char chutes[26]; 
int chutesDados = 0; 

void abertura () {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}

void chuta () { 
    char chute;
    scanf(" %c", &chute); 

    chutes[chutesDados] = chute;
    (chutesDados)++; 
} 
int jaChutou (char letra){
    int achou = 0;
    
    for (int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca() {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
            
            int achou = jaChutou(palavraSecreta[i]);

            if(achou){
                printf("%c ", palavraSecreta[i]);
            } else {   
                printf("_ ");
            }
        }
        printf("\n");
}

void escolhePalavra (){
    FILE* f; 

    f = fopen("palavras.txt", "r"); //r = read
    if(f == 0){
        printf("Desculpe, banco de dados não disponível.\n\n");
        exit(1);
    }

    int qtdDePalavras;
    fscanf(f, "%d", &qtdDePalavras);

    srand(time(0));
    int randomico = rand() % qtdDePalavras; 

    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f); //fechar arquivo
}

int acertou () {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (!jaChutou(palavraSecreta[i])) {
            return 0;
        }    
    }
    return 1;
}

int enforcou (){

    int erros = 0;

    for (int i = 0; i < chutesDados; i++){

        int existe = 0;

        for (int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){

            existe = 1;
            break;
            }
        }

        if (!existe) erros++;
    }

    return erros >= 5;
}

int main () {

    escolhePalavra (palavraSecreta);
    abertura(); 

    do {

        desenhaForca(palavraSecreta, chutes, chutesDados);
        chuta(chutes, &chutesDados); 

    } while (!acertou() && !enforcou()); //invocando ambas as funções ("negando-as")
    
}