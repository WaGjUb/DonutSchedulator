#include <stdio.h>
#include "queue.h"
#include <string.h>

int main (int argc, char** argv)
{
<<<<<<< HEAD
	Queue* execucao; //fila que será executada (schedule do arquivo)
	Queue* espera; //fila dos itens que não puderam ser executados e estao em espera
	Queue* deadlock; //irá identificar o deadlock
	char tokenaux[15]; //armazena cada ação do  	
	FILE *fp;

	fp = fopen(argv[1], "r"); 
	if (fp == NULL)
	{
		printf("O arquivo %s não existe!\n", argv[1]);
		return(1);
	}

	while (!feof(fp))
	{
		tokenaux = strtok(fp, "; ");
//		fscanf(fp, "%[^ ]", tokenaux);
		printf("%s\n", tokenaux);
	}

	fclose(fp);
=======
	Queue *exec;
	Queue *wait;
	Queue *lockItem;
	Queue *deadlock;

	
>>>>>>> 666af44d09c4a8ae4210911d9cbe52867f830472
	return(0);
}
