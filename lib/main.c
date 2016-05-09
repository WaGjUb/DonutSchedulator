#include <stdio.h>
#include "queue.h"
#include <string.h>

existeBloq(Queue *q, char val, char *quem) //TODOimplementar a correção para transação acima de 9, q->val = "a.b" a transacao e b item
{
	aux = q->first;

	while (aux!=NULL)
	{
		if (aux->val[2] == val) 
		{
			*quem  = aux->val[0]; //grava a transação que bloqueia esse dado
			return (true);
		} 

		aux = aux->next;
	}

	return(false);
}


existeDeadLock(Queue *q, char val, char *quem) //TODOimplementar a correção para transação acima de 9, q->val = "a.b" a transacao e b item
{
	aux = q->first;

	while (aux!=NULL)
	{
		if (aux->val[2] == val) 
		{
			*quem  = aux->val[0]; //grava a transação que bloqueia esse dado
			return (true);
		} 

		aux = aux->next;
	}

	return(false);
}

int main (int argc, char** argv)
{
	Queue* execucao = createQueue(); //fila que será executada (schedule do arquivo)
	Queue* espera = createQueue(); //fila dos itens que não puderam ser executados e estao em espera
	Queue* deadlock = createQueue(); //irá identificar o deadlock
	Queue* bloqueios = createQueue();
	Node deletado;
	char tokenaux[15]; //armazena cada ação do  	
	char quem;
	FILE *fp;
	FILE *out;
	
	fp = fopen(argv[1], "r"); 
	if (fp == NULL)
	{
		printf("O arquivo %s não existe!\n", argv[1]);
		return(1);
	}

	out = fopen(saida.txt, "w");

	//TODO melhorar o tokenizador!	
	fscanf(fp, "%[^\n]", tokenaux);	
	while (!feof(fp))
	{	
		int i;
		fscanf(fp, "%[^ ] ", tokenaux);
		i = strlen(tokenaux);
		tokenaux[i-1] = '\0';

		Node aux;
		aux.next = NULL;
		strcpy(aux.val, tokenaux);
		insertQueue(execucao, aux);

		printf("%s\n", tokenaux);
	}



	//roda a execução da lista TODO concertar caso haja mais de 10 transacoes
	while (execucao->size > 0)
	{

		if (execucao->first->val[0] != 'E')
		{
			if (existeBloq(bloqueios, execucao->first->val[3], &quem)) //verifica se o item já está bloqueada
			{
				Node *novoDeadlock = (Node*) malloc(sizeof(Node));
				char deadstring[10];
				deadstring[0] = quem; //bloqueador
				deadstring[1] = '.';
				deadstring[2] = execucao->first->val[1]; //bloqueado 
				deadstring[3] = '\0';  //////////////////////TODO
				strcpy(novoDeadlock->val, deadstring);
				novoDeadlock->first = NULL;
	
				insertQueue(espera, execucao->first); //insere na espera
				insertQueue(deadlock, novoDeadlock); //insere deadlock
				//TODO rodar aqui uma função que verifica se há o deadlock
				removeQueue(execucao, &deletado); //deleta da execução
	
			}
			else
			{
				if (execucao->first->val[0] == 'W')
				{
					Node *novoBloqueio = (Node*) malloc(sizeof(Node));
					char valor[5];
	
					valor[0] = execucao->first->val[1]; //transacao
					valor[1] = '.';
					valor[2] = execucao->first->val[3]; //valor
					valor[3] = '\0';
					strcpy(novoBloqueio->val,valor); 
					insertQueue(bloqueios, novoBloqueio); //bloqueia o dado
					
				}
				
				fprintf(out, "%s; ",execucao->first->val);
				removeQueue(execucao, &deletado);
			}
		else //commit entao libera
		{
			if (existeDeadlock(deadlock, execucao->first->val[1], &quem)) //verifica se a transação que quer commitar está bloqueada
			{
				insertQueue(espera, execucao->first); //insere na espera
				removeQueue(execucao, &deletado); //deleta da execução
			}

			else
				{
			//TODO função que encontra dentro de bloqueio os itens bloqueados por esta transação e apaga os nós
			//TODO função que remove o deadlock desses dados também
			
				while (espera->size > 0) //esvazia a fila de espera para uma reexecução
				{
					insertFirst(execucao, espera->last);
					removeLast(espera, &deletado);
				}
			}
		}
	}
	

	if (espera->size > 0)
	{
		fclose(out);
		out = fopen(saida.txt, "w"); //recria o arquivo
		fprintf(out, "DEADLOCK ENCONTRADO – TRANSAÇOES ENVOLVIDAS ")
		while(deadlock->size > 0) 
		{
			removeQueue(deadlock, &deletado);
			printf("T%c, T%c,", deletado->var[0], deletado->var[2]);
		}
			
		
	}

	fclose(fp);
	fclose(out);
	return(0);
}
