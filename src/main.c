#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/queue.h"

bool existeBloq(Queue *q, char val, char *quem) //TODOimplementar a correção para transação acima de 9, q->val = "a.b" a transacao e b item
{
	Node *aux;
	aux = q->first;

	while (aux!=NULL)
	{
		if (aux->val[2] == val) 
		{
			*quem  = aux->val[0]; //grava a transação que bloqueia esse dado
//			printf("existe bloqueio"); ////////////////////////////////////////////////////////TODO DELETE
			return (true);
		} 

		aux = aux->next;
	}

	return(false);
}

bool existeBloqAB(Queue *q, char* string) 
{
	Node *aux;
	aux = q->first;

	while (aux!=NULL)
	{
		if (!strcmp(aux->val, string)) //se as strings forem iguais
		{
			return (true);
		} 

		aux = aux->next;
	}

	return(false);
}



bool existeBlockDeadlock(Queue *q, char val, char *quem) //TODOimplementar a correção para transação acima de 9, q->val = "a.b" a transacao e b item
{
	Node* aux;
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


void removeFromItem(Queue* q, char trans) //remove deadlock e bloq
{

	Node *aux;		
	aux = q->first;
	Node *auxprev = NULL;
	bool removed = false;
	while (aux!=NULL)
	{
		if (aux->val[0] == trans)  
		{	if ((auxprev == NULL) || ((aux->next == NULL) && (q->size>1)))
			{
				if (auxprev == NULL)
				{
					aux->next = NULL;
					q->first = q->first->next;
				}		

				if ((aux->next == NULL) && (q->size>1))
				{
					q->last = NULL;
					q->first = NULL;
				}
			}
			else
			{
				auxprev->next = aux->next;
			}
			aux->next = NULL;
			free(aux);
			q->size--;
			removed = true;
		}
		if (removed)
		{
			auxprev = NULL;
			aux = q->first;
			removed = false;
		} 
		else
		{
			auxprev = aux;
			aux = aux->next;
		}
	}

}

	void printLista(Queue *q)
	{
		Node* aux;
		
		aux = q->first;
		
		printf("PRINT LISTA\n");
		while(aux!=NULL)
		{
		printf("%s\n", aux->val); 
		aux=aux->next;
		}
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
	argc++; //elimina o warning

	fp = fopen(argv[1], "r"); //TODO argv[1]
	if (fp == NULL)
	{
		printf("O arquivo %s não existe!\n", argv[1]);
		return(1);
	}

	out = fopen("saida.txt", "w");

	//TODO melhorar o tokenizador!	
	char ignore;
	fscanf(fp, "%[^\n]%c", tokenaux, &ignore);	
	while (!feof(fp))
	{	
		int i;
		fscanf(fp, "%[^ ] ", tokenaux);
		i = strlen(tokenaux);
		if(i > 6)
		{
			fclose(fp);
			fclose(out);
			printf("DonutSchedulator suporta no maximo 10 transações (de T0 até T9), insira uma entrada válida!\n");
			return(0);
		}
		tokenaux[i-1] = '\0';

		Node aux;
		aux.next = NULL;
		strcpy(aux.val, tokenaux);
//		printf("valor->>> %s\n",aux.val);
		if (aux.val[0] != 'S')
		{
			insertQueue(execucao, aux);
		}
//		printf("-%s\n", tokenaux);
//		printLista(execucao);
	}



	//roda a execução da lista TODO concertar caso haja mais de 10 transacoes
	while (execucao->size > 0)
	{
		if (execucao->first->val[0] != 'E')
		{
			if (existeBloq(bloqueios, execucao->first->val[3], &quem) && (quem != execucao->first->val[1])) //verifica se o item já está bloqueada
			{//printf("aqui, size->%d\n", execucao->size);
				Node *novoDeadlock = (Node*) malloc(sizeof(Node));
				char deadstring[10];
				deadstring[0] = quem; //bloqueador
				deadstring[1] = '.';
				deadstring[2] = execucao->first->val[1]; //bloqueado 
				deadstring[3] = '\0';  //////////////////////TODO
				strcpy(novoDeadlock->val, deadstring);


				Node* novaEspera = (Node*) malloc(sizeof(Node));
				strcpy(novaEspera->val, execucao->first->val);
				novaEspera->next = NULL;

				if (!existeBloqAB(deadlock, deadstring)) //se o deadlock não existe esse nó
				{
					insertQueue(deadlock, *novoDeadlock); //insere deadlock
					free(novoDeadlock);
				}

				insertQueue(espera, *novaEspera); //insere na espera
				free(novaEspera);
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

					//TODO nao inserir mais de um bloqueio

					insertQueue(bloqueios, *novoBloqueio); //bloqueia o dado
					free(novoBloqueio);

				}
		
				fprintf(out, "%s; ", execucao->first->val);
			//	printf("Adicionado: %c%c%c%c\n ",execucao->first->val[0],execucao->first->val[1],execucao->first->val[2],execucao->first->val[3]);
				removeQueue(execucao, &deletado);
			}
		}
		else //commit entao libera
		{

//printf("ANTES-->>>>>>COMMIT %c\n", execucao->first->val[1]);
//printLista(deadlock);
//printf("\nBLOQUEIO\n");
//printLista(bloqueios);
			if (existeBlockDeadlock(deadlock, execucao->first->val[1], &quem)) //verifica se a transação que quer commitar está bloqueada
			{
				Node novaEspera;
				strcpy(novaEspera.val, execucao->first->val);
				novaEspera.next = NULL;

				insertQueue(espera, novaEspera); //insere na espera
				removeQueue(execucao, &deletado); //deleta da execução
			}

			else 
			{
				removeFromItem(bloqueios, execucao->first->val[1]);
				removeFromItem(deadlock, execucao->first->val[1]);
				fprintf(out, "C%s; ",execucao->first->val+1);
				removeQueue(execucao, &deletado);

				while (espera->size > 0) //esvazia a fila de espera para uma reexecução
				{
					Node novaExecucao;
					novaExecucao.next = NULL;
					strcpy(novaExecucao.val, espera->last->val);
					
					insertFirst(execucao, novaExecucao);
					removeLast(espera, &deletado);
				}
			}
//	printf("\nPOS DEAD\n");
//	printLista(deadlock);
//printf("\nBLOQUEIO POS\n");
//	printLista(bloqueios);
	}
	}


	if (espera->size > 0)
	{
		fclose(out);
		out = fopen("saida.txt", "w"); //recria o arquivo
		fprintf(out, "DEADLOCK ENCONTRADO – TRANSAÇOES ENVOLVIDAS ");
		char trde[20]={"aaaaaaaaaaaaaaaaaaa"};
		int count = 0;
		int oldcount =0;
			while(deadlock->size > 0) 
			{
				removeQueue(deadlock, &deletado);
				trde[deletado.val[0]-'0'] = 'b';
				trde[deletado.val[2]-'0'] = 'b';
//				printf("T%c, T%c,", deletado.val[0], deletado.val[2]);
			}
			int j;
			int tamanhostring = strlen(trde);; //elimina o warning da comparação
			for (j=0; j<tamanhostring; j++)
			{			
				if (trde[j] == 'b')
				{
					if (count > oldcount)
					{
						fprintf(out,", ");
					}
					fprintf(out,"T%d", j);
					oldcount = count;
					count++;
				}

			}
	}

	fclose(fp);
	fclose(out);
	return(0);
}
