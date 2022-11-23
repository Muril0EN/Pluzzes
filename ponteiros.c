#include <stdio.h>

void calcula (int c){
    printf("calcula %d %d\n", c, &c);
    c++;
    printf("calcula %d %d\n", c, &c);
}

int main (){
    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(c); //passagem por cópia
    printf("main %d %d\n", c, &c);
} //o nome declarado em cada variável de cada função é independente, por isso a saída "estranha"