#include <stdio.h>
#include <stdlib.h>

int main () {
//não existem strings na linguagem C! 
// a saída é usar uma lista (array) de caracteres (char)
// sintaxe para declarar-> tipo nome [tamanho];
// sintaxe para atribuir-> nome [posição] = 10; (semelhante para imprimir) 
    char palavraSecreta [20];
//imprimir array
    sprintf(palavraSecreta, "melancia"); //função para simular string
    printf("%s\n", palavraSecreta); //%s usado para imprimir string de char 
    
}