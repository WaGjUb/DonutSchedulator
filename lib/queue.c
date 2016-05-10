//#ifndef __QUEUE__
//#define __QUEUE__
#include "queue.h"
#include <stdlib.h>
#include <string.h>

void initialize(Queue *q)
{
	q->first = NULL;
	q->size = 0;
}

Queue* createQueue()
{
	Queue* q;
	q = (Queue*) malloc(sizeof(Queue));
	initialize(q);
	return (q);
} 

bool insertQueue(Queue *q, Node n)
{
	
	Node *new;
	
	new = (Node*) malloc(sizeof(Node)); //cria novo nó
	new->next = NULL; //nxt = null
	strcpy(new->val, n.val); //copia a string

	if (q->first == NULL)
	{
		q->first = new; //se for primeiro ja entra como primeiro
		
	}
	else
	{
		q->last->next = new; //se nao ja entra no lugar do ultimo
	}
	
	q->last = new; // a lista aponta o last para ultimo
	q->size++; //add 1 no tamanho da lista
	return(true);
	
}

bool removeQueue(Queue *q, Node *n)
{
	if (q->first == NULL)
	{
		n = NULL;
		return(false);
	}	
	
	
	Node *aux;

	aux = (Node*) malloc(sizeof(Node));
	strcpy(n->val, q->first->val);
	aux = q->first;
	q->first = q->first->next;
	q->size--;
	aux->next = NULL;
	free(aux);	
	return(true);
	
}


bool removeLast(Queue *q, Node *n)
{
	if (q->size > 1)
	{
	if (q->last == NULL)
	{
		n = NULL;
		return(false);
	}	
	
	
	Node *aux;
	aux = q->first;
	while (aux->next != q->last)
	{
		aux = aux->next;
	}

	q->last = aux;

	aux = (Node*) malloc(sizeof(Node));
	strcpy(n->val, q->last->next->val);
	aux = q->last->next;
	q->size--;
	q->last->next = NULL;
	free(aux);
	}

	else
	{
		if (q->size == 0)
		{
			return(false);
		}
	
		if(q->size == 1)
		{
			free (q->last);
			q->last = NULL;
			q->first = NULL;
			q->size = 0;
			return(true);
		}
	}	
	return(true);
	
}

bool insertFirst(Queue *q, Node n)
{
	
	Node *new;
	
	new = (Node*) malloc(sizeof(Node)); //cria novo nó
	new->next = q->first; //nxt = first
	strcpy(new->val, n.val); //copia a string

	if (q->size == 0)
	{
		q->last = new;
	}

	q->first = new;

	q->size++; //add 1 no tamanho da lista
	return(true);
	
}


//#endif

