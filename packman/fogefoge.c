#include <stdio.h>
#include <stdlib.h>

char** mapa; //declaração de ponteiros de ponteiros (necessário para matriz)
int linhas;
int colunas; 

void liberaMapa (){
    for(int i = 0; i < linhas; i++){//
        free(mapa[i]);//liberar memória de cada uma das linhas (ponteiros)
    }
    free(mapa);
}

void alocaMapa(){
    mapa = malloc(sizeof(char*) * linhas);//malloc -> alocação dinâmica de mem. / sizeoff -> informa qtd de bytes cada tipo de var precisa / * -> multiplica quantidade  que vai 'entrar'
    for(int i = 0; i < linhas; i++){// para cada linha
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); //alocar 'vezes' quantidade de colunas 
    }
}

void leMapa (){
    FILE* arquivo; //nome do arquivo
    arquivo = fopen("mapa.txt", "r"); //lê arquivo
    if(arquivo == 0) { //trata erro e fecha o programa em caso de problemas com o arquivo
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &linhas, &colunas); //

    alocaMapa();

    for (int i = 0; i < 5; i++){
        fscanf(arquivo, "%s", mapa[i]);
    }
    fclose(arquivo);//fecha o arquivo
}

int main(){

    leMapa();
    
    for (int i = 0; i < 5; i++){//imprimir arquivo
        printf("%s\n", mapa[i]);//
    }
    
    liberaMapa();
}