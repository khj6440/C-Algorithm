#include<stdio.h>
#include<stdlib.h>



typedef int element;

typedef struct node
{
	element data;
	struct node *link;
}node;

node *head;

void creatList();//공백리스트 생성
node *makeNode(element);//노드생성
void insertLastNode(node *);//리스트에 노드삽입 (매개변수 노드 포인터형)
void printList();//리스트를 출력
void deleteLastNode();//리스트에서 노드삭제

int main()
{
	creatList();
	insertLastNode(makeNode(10));
	insertLastNode(makeNode(20));
	insertLastNode(makeNode(30));
	insertLastNode(makeNode(40));
	insertLastNode(makeNode(50));
	
	printList();// [50 40 30 20 10]
	deleteLastNode();
	printList();// [40 30 20 10]
	deleteLastNode();
	printList();// [30 20 10]
	deleteLastNode();
	printList();// [20 10]
	deleteLastNode();
	printList();// [10]
	deleteLastNode();
	printList();// []
	deleteLastNode();//empty list
	printList();
	return 0;
}

void creatList()
{
	head=NULL;
}  //공백리스트생성

node *makeNode(element data)
{
	node *newNode=(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->link=NULL;

	return newNode;
}
void insertLastNode(node *newNode)
{
	node* p=head;
	if(head==NULL)
	{
		head=newNode;
		return;
	}
	while(p->link!=NULL)//마지막노드탐색
		p=p->link;
	p->link=newNode;
}
void printList()
{
	node *p = head;
	printf("[ ");

	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
	printf("]\n");
}
void deleteLastNode()
{
	node *p =head;
	node *q =head;

	if(head ==NULL)
	{
		printf("no deletion! empty list!!\n");
		return;
	}
	while(p->link!=NULL)
	{
		q=p;
		p=p->link;
	}
	//하나 남은 노드를 삭제하는경우 
	if(head==p)
		head=NULL;
	free(p);
	q->link=NULL;
}
