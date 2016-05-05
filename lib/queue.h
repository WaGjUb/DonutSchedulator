#ifndef __QUEUE__
#define __QUEUE__

typedef struct node
{
	struct node *next;
	char val[16]; //R1(x) <-- exemplo

} Node;

typedef struct scheduleQueue
{
	Node *first;
	int size;
}Queue;

typedef enum Boolean 
{
true=1, false=0
} bool;

void initialize(Queue *q)
Queue* createQueue()
bool insertQueue(Queue *q, Node n)
bool removeQueue(Queue *q, Node *n)

#endif
