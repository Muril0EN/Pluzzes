#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int segundos = time(0); /*variável que recebe como valor o retorno da função que devolve número de segundos desde EPOCH*/
    srand(segundos); /*função que atribui o retorno da função à semente que será usada para gerar números aleatórios*/

    int n1 = rand();/*função que gera número randômico, usando a semente 'plantada em srand'*/
    int n2 = rand();

/*para limitar os valores que serão aprensentados, pode-se usar o operador de resto da divisão %*/

    int intervaloDeZeroNoveNove = n1 % 100;
    int intervaloDeZeroNove = n1 % 10;
    int intervaloDeZeroQuatro = n1 % 5;

    printf("Número randomico de 0 - 99 = %d\nNúmero randomico de 0 - 9 = %d\nNúmero randomico de 0 - 4 = %d\n\n", intervaloDeZeroNoveNove, intervaloDeZeroNove, intervaloDeZeroQuatro);
}