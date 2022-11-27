#include <stdio.h>

void calcula (int* c){//informa que algoritmo vai receber o endereço de memória da variável, um ponteiro
    //printf("calcula %d %d\n", c, &c);// o '&' é o caractere reservado para informar à linguagem qual o endereço de memória 
    printf("calcula %d %d\n", (*c), c);
    (*c)++;//vai puxar o valor presente no endereço de memória
    printf("calcula %d %d\n", (*c), c);
}

int main (){
    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(c); //passagem por cópia
    printf("main %d %d\n", c, &c);
} //o nome declarado em cada variável de cada função é independente, por isso a saída "estranha"