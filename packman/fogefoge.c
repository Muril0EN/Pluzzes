#include <stdio.h>

int main(){
    
//como não declarar a matriz    
    /*char linha1[10];
    char linha2[10];
    char linha3[10];
    char linha4[10];
    char linha5[10];*/
//maneira correta de declarar a matriz ->  tipo nome [linhas][colunas];
    char mapa[5][10];
//manipular -> nome [indice] [indice]
    mapa[0][9] = '|';
    mapa[4][9] = '@';
//imprimir elemento da matriz -> printf(%tipo, nome[indice][indice])
    printf("%c %c\n", mapa[0][9], mapa[4][9]);
}