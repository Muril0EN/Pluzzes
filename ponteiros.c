#include <stdio.h>

void calcula (int c){
    printf("calcula %d\n", c);
    c++;
    printf("calcula %d\n", c);
}

int main (){
    int c = 10;

    printf("main %d\n", c);
    calcula(c); //passagem por cópia
    printf("main %d\n", c);
} //o nome declarado em cada variável de cada função é independente, por isso a saída "estranha"