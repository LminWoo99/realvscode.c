#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  SIZE 10
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct { // ≈• ≈∏¿‘
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;


void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}


int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}


int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화 상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}


element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백 상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS  3
void radix_sort(int list[], int n)
{
	int i, b, d, k, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b<BUCKETS; b++) init_queue(&queues[b]);  
	for (d = 0; d<DIGITS; d++) {
		for (i = 0; i<n; i++) {     
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}

		printf("DIGITS = %d\n", d+1);
        for (i = 0; i<n; i++){
        	printf("queues[%d]=> ", i);
            int j;
			for ( j = queues[i].front+1; j <= queues[i].rear ;j++)
			    printf("%d  -> ", queues[i].data[j]);
			printf("\n");	 
        }
	     
		for (b = i = 0; b<BUCKETS; b++)  
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;					
		for (i = 0; i<SIZE; i++)
		    printf("%d  ", list[i]);
		printf("\n");    
	}
}

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	int i;
	for (i = 0; i<SIZE; i++){      	
		list[i] = rand() % 1000;
        printf("%d  ", list[i]);
    }
    printf("\n");
	radix_sort(list, SIZE); 
//	for (i = 0; i<SIZE; i++)
//		printf("%d  ", list[i]);
//	printf("\n");
	return 0;
}
