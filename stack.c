#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct node
{
	element data;
	struct node *link;
}node;

node *top;

void createStack(); //공백스택 생성
node *makeNode(element);//노드를 생성
void push(node *);//push
element pop(); //pop
void printStack();
element isEmpty();

int main()
{
	createStack();
	push(makeNode(10));
	push(makeNode(20));
	push(makeNode(30));

	printStack();

	printf("pop = %d\n",pop());
	printStack(); // [20 10]
	printf("pop = %d\n",pop());
	printStack(); // [10]
	printf("pop = %d\n",pop());
	printStack(); // [ ]

	printf("%d\n",pop());
	return 0;
}

void createStack()
{
	top = NULL;
}

node *makeNode(element data)
{
	node * newNode;
	newNode=(node *)malloc(sizeof(node));

	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}
void push(node *newNode)
{
	newNode->link = top;
	top = newNode;
}
void printStack()
{
	node *p = top;
	printf("[ ");

	while(p)  //while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
	printf("]\n");
}
element pop()
{
	node *temp =top;
	element item;

	if(isEmpty())
	{
		printf("Stack Underflow!!\n");
		return -1;
	}

	item = temp->data;
	top = temp->link;
	free(temp);

	return item;
}
element isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
		
