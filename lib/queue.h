#ifndef __QUEUE__
#define __QUEUE__

typedef struct node
{
	struct node *next;
	char val[10]; //R1(x) OU A1 OU 2.3 <-- exemplo1 schedule, exemplo 2 item a bloqueado por t1 e exemplo 3 t2 espera t3

} Node; //para deadlock usaremos val[0] = transação que bloqueou o dado e val[1] = transacao que está esperando o dado ser desbloqueado BLOQUEI ESCRITA	

typedef struct scheduleQueue
{
	Node *first; 
	Node *last;
	int size;
}Queue; //fila de execução geral e da espera


typedef enum Boolean 
{
true=1, false=0
} bool;

void initialize(Queue *q);
Queue* createQueue();
bool insertQueue(Queue *q, Node n);
bool insertFirst(Queue *q, Node n);
bool removeQueue(Queue *q, Node *n);

#endif
