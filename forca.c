#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
//não existem strings na linguagem C! 
// a saída é usar uma lista (array) de caracteres (char)
// sintaxe para declarar-> tipo nome [tamanho];
// sintaxe para atribuir-> nome [posição] = 10; (semelhante para imprimir) 
    char palavraSecreta [20];
//imprimir array
    sprintf(palavraSecreta, "melancia"); //função que ajuda a escrever palavras dentro de arrays de chars
    //printf("%s\n", palavraSecreta); //%s usado para imprimir array de char 

    int acertou = 0;
    int enforcou = 0;

    do {
        char chute;/* code */
        scanf("%c", &chute);

        for(int i = 0; i < strlen(palavraSecreta); i++) {
            if(palavraSecreta[i] == chute){
                printf("A posição %d tem essa letra!\n", i);
            }
        }
    } while (!acertou && !enforcou); // = (acertou == 0 && enforcou == 0), isso pq '!' é operador de negação.
    
    

}