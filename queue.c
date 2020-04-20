#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct node
{
	element data;
	struct node *link;
}QNode;

typedef struct
{
	QNode *front;
	QNode *rear;
}QType;

QType *createQueue();
void enQueue(QType *,element);
void printQueue(QType *);
element deQueue(QType *);
int isEmpty(QType *);

int main()
{
	QType *LQ1=createQueue();
	enQueue(LQ1,'A');
	enQueue(LQ1,'B');
	enQueue(LQ1,'C');

	printQueue(LQ1);//[A B C]
	
	printf("%c\n",deQueue(LQ1)); //A
	printQueue(LQ1); // [B C]

	printf("%c\n",deQueue(LQ1)); //A
	printQueue(LQ1); // [B]

	printf("%c\n",deQueue(LQ1)); //A
	printQueue(LQ1); // []

	printf("%c\n",deQueue(LQ1));
	return 0;
}

QType *createQueue()
{
	QType *LQ=(QType *)malloc(sizeof(QType));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}
void enQueue(QType *LQ, element item)
{
	QNode *newNode =(QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if(LQ->front == NULL) //공백큐인가?
		LQ->front = LQ->rear = newNode;
	else
	{
		LQ->rear->link=newNode;
		LQ->rear = newNode;
	}
}
void printQueue(QType *LQ)
{
	QNode *p = LQ->front;
	printf("[ ");
	while(p!=NULL)
	{
		printf("%c ",p->data);
		p=p->link;
	}
	printf("]\n");
}
element deQueue(QType *LQ)
{
	QNode *old = LQ->front;
	element item;
	if(isEmpty(LQ))
		return '0';
	item= old->data;
	LQ->front=old->link; //LQ->front->link;
	if(LQ->front ==NULL)
		LQ->rear=NULL;
	free(old);

	return item;
}
int isEmpty(QType *LQ)
{
	if(LQ->front ==NULL)
		return 1;
	else
		return 0;
}


