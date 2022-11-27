#include <stdio.h>
#include <string.h>

//declaração da função -> funções facilitam a leitura manutenção, reutilização de códigos 
void abertura () {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}
//declaração da função fora da função principal
void chuta (char chutes[26], int* tentativas) { //sintaxe para declaração de parametros -> tipo nome
    char chute;
    scanf(" %c", &chute); //comando para ignorar o 'enter' pq fica o 'enter' fica no buffer (só necessário em algoritmos com char)

    chutes[*tentativas] = chute;
    (*tentativas)++; //incremento no conteúdo ponteiro
} //**** a razão para a variável chutes não ter sido reescrita é pq um array já é um ponteiro.
//funcções 'void' não devolve nada. Aqui precisamos devolver um inteiro
int jaChutou (char letra, char chutes [26], int tentativas){
    int achou = 0;
    
    for (int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

int main () {
 
    char palavraSecreta [20];
//imprimir array
    sprintf(palavraSecreta, "melancia"); //função que ajuda a escrever palavras dentro de arrays de chars
    //printf("%s\n", palavraSecreta); //%s usado para imprimir array de char 

    int acertou = 0;
    int enforcou = 0;

    char chutes[26]; //tamanho do alfabeto estendido
    int tentativas = 0; 

    //abertura
    abertura(); //chamada de função de clarada na linha 4;

    do {

        for (int i = 0; i < strlen(palavraSecreta); i++) {//função strlen devolve o tamanho do array
            
            //retorno da função jaChutou atribuído à variável achou;
            int achou = jaChutou(palavraSecreta[i], chutes, tentativas);

                if(achou){
                    printf("%c ", palavraSecreta[i]);
                } else {   
                    printf("_ ");
                }
        }
        printf("\n");
        
        chuta(chutes, &tentativas); //para usar o endereço de memória da variável tentativas, para entregar o valor desse endereço para a função
        //tentativas++;//esse passo deve estar dentro da função (boa prática)

    } while (!acertou && !enforcou); // = (acertou == 0 && enforcou == 0), isso pq '!' é operador de negação.
    
}