#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "fibonacci.h"
#include <stdio.h>

int main() {
	pid_t pid;

	// Cria um processo filho
	pid = fork();

	// Verifica se houve erro na criação do processo filho
	if (pid < 0) {

		// Exibe uma mensagem de erro
		printf("\nErro na criação do processo filho!\n");
		return 1;

	} else if (pid == 0) { // Processo filho criado

		printf("\nOlá! Sou o processo filho criado!");
		printf("\nTenho o identificador (filho) numero %d", getpid());	
		printf("\nTchau!\n");

		// Chama a função fibonacci
		fibonacci();

	} else {
		
		// Código a ser executado pelo processo pai
		// O pai espera até que o processo filho termine
		wait(NULL);
		printf("\nOla! Sou o processo pai!");
		printf("\nCriei um processo filho de numero %d. Ele já encerrou!", pid);
		printf("\nMeu identificador (pai) é o numero %d", getpid());	
		printf("\nEncerrando também!\n");
	}
	return 0;
}

