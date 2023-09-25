#include <stdio.h>
#include <stdlib.h>

// Função para calcular e exibir a série de Fibonacci
void fibonacci() {
	int *fib;      // Ponteiro para armazenar a série de Fibonacci
	int num;       // Número de termos desejados na série
	int i;

	// Solicita ao usuário o número de termos a serem exibidos
	printf("\nDigite a quantidade de termos para exibir na série de Fibonacci: ");
	scanf("%d", &num);

	// Verifica se o número de termos é válido
	if (num <= 0) {
		printf("\nA quantidade de termos deve ser um número positivo e não nulo!\n");
		return;  // Encerra a função se o número de termos não for válido
	}

	// Aloca dinamicamente memória para armazenar os termos da série
	fib = (int *) calloc(num, sizeof(int));

	// Verifica se a alocação de memória foi bem-sucedida
	if (!fib) {
		printf("\nNão há memória suficiente para armazenar os termos da série de Fibonacci!\n");
		return;  // Encerra a função se a alocação de memória falhou
	}

	// Inicializa os dois primeiros termos da série
	fib[0] = 0;
	fib[1] = 1;

	// Calcula os termos restantes da série
	for (i = 2; i < num; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	// Exibe os termos da série de Fibonacci
	printf("\n\t\t");
	for (i = 0; i < num; i++) {
		printf(" %d ", fib[i]);
	}
	printf("\n\n");

	// Libera a memória alocada dinamicamente
	free(fib);
}