#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h" //biblioteca ****
#include "mapa.h"

MAPA m; 

int acabou(){
    return 0;//o retorno 0 garante que o jogo não acabe;
}

void mover(char direcao) {
    int x;//inicialização da posição na horizontal; 
    int y;//inicialização da posição na vertical;

    for (int i = 0; i < m.linhas; i++) { //lê linhas
        for (int j = 0; i < m.colunas; i++) { //lê colunas 
            if (m.matriz[i][j] == '@') { //encontra herói
                x = i;//atribui valor encontrado, referente a posição no eixo horizontal, à variável decalarada acima;
                y = j;//idem anterior mas para o eixo vertical;
                break;//interrompe a execução da fucnção
            }
        }
    }
    
    switch (direcao){//if ternário para redução de código;
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

    m.matriz[x][y] = '.'; //substitui posição do packman por 'vazio' após movimentação do herói;

}

int main(){

    leMapa(&m);//passa como parâmetro para a função 'leMapa' o endereço de memória da variável 'm';
    
    do { //loop principal
        imprimeMapa(&m);

        char comando;//declaração da variável que vai receber o comando para mover o herói
        scanf(" %c", &comando);//recebe do teclado o comando acima
        
        mover(comando);//chama a função para mover o herói passando comando de input como parâmetro;

    } while(!acabou());//passa como parâmetro a negação da função acabou para o while (que sempre recebe um bool). 
    
    liberaMapa(&m);//chama a função que libera mapa usando como parâmetro o ponteiro do mapa;
}