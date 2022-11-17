#include <stdio.h>
#include <stdlib.h> /*biblioteca onde está a função abs() -> função que estrai número absoluto*/
#include <time.h> /*biblioteca onde está a função time*/

int main (){
	printf("************************************\n");
	printf("* Bem vindo ao jogo de adivinhação *\n");
	printf("************************************\n");
//comentário de linha 	
/*comentário de bloco*/
/*Gerando numeros randomicos*/	
	int segundos = time(0);/*a função time(0) retorna o número de segundos desde 1 de janeiro de 1970 (EPOCH)*/
	srand(segundos);/*essa função é a semente para função rand()*/
	
	int numeroGrande = rand(); /*vai devolver número aleatório pq tem semente do srand() que muda sempre*/

	int numeroSecreto = numeroGrande % 100; /*usando a operação de resto da divisão (%) conseguimos controlar o tamanho do número*/

	int chute; /*quando uma variável é usada, ela já foi inicializada (mesmo que indiretamente)*/
	printf("chute %d\n", chute); /*retorna o número referente á região de memória do programa anterior. Esse valor será usado no programa caso a variável não tenha sido inicializada.*/
	int tentativas = 1;

	double pontos = 1000;

	while (1){ /*sintaxe para looping infinito*/
		printf(" * Tentativa %d *\n", tentativas);/*ajuste pq tentativas é declarado como 0*/
		printf("Digite seu chute:");
		scanf("%d", &chute);

		if(chute < 0){ /*validando a entrada do usuário*/
			printf("Você não pode chutar número negativos!\n");
			
			continue; /*faz com que o código continue, indo para a próxima iteração 'i++'
			antes de seguir a executar o resto do código (economiza execução)*/
		}

		int acertou = (chute == numeroSecreto);
		int maior = chute > numeroSecreto;

		if(acertou){
			printf("Você acertou, parabéns!\n\n");
			
			break;/*usar quando houver looping infinito*/
		} 
		
		else if (maior){ /*quando se 'combina' else if elimina verificações desnecessárias*/
			printf("Você errou, seu chute foi maior que o número secreto.\n\n");
		}
		else {
			printf("Você errou, seu chute foi menor que o número secreto.\n\n");
		}

		tentativas++;

		double pontosPerdidos = abs(chute - numeroSecreto) / (double)2; /* a conversão de variáveis é chamada de casting*/
		pontos = pontos - pontosPerdidos;	/*função abs(), usada na linha superior, extrai número absoluto. Ou seja, sempre devolve um número positivo*/
	}

	printf("Fim de jogo!\n");
	printf("Você acertou em %d tentativas!\n", tentativas);
	printf("Total de pontos: %.1f\n", pontos); /*ajuste do número de casas decimais no %.xf, onde x = casas decimais*/
}
/*Inteiros*/
	/*short = 2 bytes*/
	/*int = 4 bytes = 32bits ou 2**32*/
	/*long = 8 bytes = 64bits ou 2**64*/
/*decimais*/
	/*doble = 8 bytes = 64bits ou 2**64*/
	/*float = 4 bytes = 32bits ou 2**32*/