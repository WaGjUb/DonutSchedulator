#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../lib/queue.h"

int tasksCount(file* fp) //conta a quantidade de transações TODO fp e scan
{
	if (fp = EOF) //se existir apenas um arquivo em branco
	{
		return(0);
	}

	char c;
	int qnt = 1;

	while (fscanf(fp, "%c", &c) != EOF) 
	{
		if (c == '\0') 
		{
			qnt++;
		}
	}
	return(qnt);
}

addTasks(file* fp, Queue* t, int size)
{
	
	task = (Queue*) malloc(tasksqnt*sizeof(Queue));
//		createQueue(task[i]);	
//		insertQueue(task[i], getNode()); //TODO implementar getNode
}

Bool scheduleC(Queue* s ,Queue* t, int size)
{
	int sort, i;
	v = 0;
	
	while (v != size) //TODO verificar este while caso entre num loop infinito
	{
		v=0;
		sort = rand%size;

		if (t[sort]->size != 0)
		{
			Node n;
			insertQueue(&s, removeQueue(t[sort], &n));
		}

		else
		{
			for(i=0; i<size; i++)
			{
				if (t[i]->size == 0)
				{
					v++;
				}
			}
		}
	}
}

int main(int argc, char* argv)
{
	file* f;
	//fp = fopen (argv[1], "r"); //TODO verificar a sintaxe
	
	int i;
	int tasksqnt = tasksCount;
	Queue* tasks;
	Queue schedule;
	
	//TODO rewind fp

	addTasks();
	
	schedule = createQueue;
	
	scheduleC(&schedule, tasks, tasksqnt);
	return 0;
}
