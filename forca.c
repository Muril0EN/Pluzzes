#include <stdio.h>
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

    char chutes[26]; //tamanho do alfabeto estendido
    int tentativas = 0; 

    do {

        for (int i = 0; i < strlen(palavraSecreta); i++) {//função strlen devolve o tamanho do array
            
            int achou = 0;

            for (int j = 0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }

                if(achou){
                    printf("%c ", palavraSecreta[i]);
                } else {   
                    printf("_ ");
                }
        }
        printf("\n");
        
        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute); //comando para ignorar o 'enter' pq fica o 'enter' fica no buffer (só necessário em algoritmos com char)

        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou); // = (acertou == 0 && enforcou == 0), isso pq '!' é operador de negação.
    
}