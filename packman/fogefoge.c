#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h"

MAPA m; // definindo o nome através da função 'typedef' no .h pode-se atribuir a struct a uma variável

void leMapa (){
    FILE* arquivo; //nome do arquivo
    arquivo = fopen("mapa.txt", "r"); //lê arquivo
    if(arquivo == 0) { //trata erro e fecha o programa em caso de problemas com o arquivo
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &(m.linhas), &(m.colunas)); //

    alocaMapa();

    for (int i = 0; i < 5; i++){
        fscanf(arquivo, "%s", m.matriz[i]);
    }
    
    fclose(arquivo);//fecha o arquivo
}

void alocaMapa(){
    m.matriz = malloc(sizeof(char*) * m.linhas);//malloc -> alocação dinâmica de mem. / sizeoff -> informa qtd de bytes cada tipo de var precisa / * -> multiplica quantidade  que vai 'entrar'
    
    for(int i = 0; i < m.linhas; i++){// para cada linha
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1)); //alocar 'vezes' quantidade de colunas 
    }
}

void liberaMapa (){
    for(int i = 0; i < m.linhas; i++){//
        free(m.matriz[i]);//liberar memória de cada uma das linhas (ponteiros)
    }
    free(m.matriz);
}

int acabou(){
    return 0; //jogo sem final, por enquanto
}

void move(char direcao) {
    int x;
    int y;

    //le a matrix e encontra a posição do herói
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; i < m.colunas; i++) {
            if (m.matriz[i][j] == '@') {
                x = i;//posição herói
                y = j;    
                break;
            }
        }
    }
    
    switch (direcao){
        case 'a':
            m.matriz[x][y-1] = '@';//esquerda
            break;
        case 'w':
            m.matriz[x-1][y] = '@';//pra cima 
            break;
        case 's':
            m.matriz[x+1][y] = '@';//pra baixo
            break;
        case 'd':
            m.matriz[x][y+1] = '@';//direita
            break;
    }

    m.matriz[x][y] = '.'; //substitui posição do packman por 'vazio'

}

void imprimeMapa(){
    for (int i = 0; i < 5; i++){//imprimir arquivo
        printf("%s\n", m.matriz[i]);//
    }
}

int main(){

    leMapa();
    
    do { //loop principal
        imprimeMapa();

        char comando;
        scanf(" %c", &comando);
        
        move(comando);

    } while(!acabou());
    
    liberaMapa();
}