#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct node
{
	struct node* llink;
	struct node* rlink;
	element data;
}node;

node *head;

void createList();
node *makeNode(element data);
void insertNode(node *);
void deleteNode(element data);
void printList();
void searchNode(element);

int main()
{
	createList();
	insertNode(makeNode('1'));
	insertNode(makeNode('2'));
	insertNode(makeNode('5'));
	insertNode(makeNode('7'));
	insertNode(makeNode('0'));
	printList();

	searchNode('7');

	deleteNode('9');//no item

	deleteNode('0');
	printList(); // [5 10 15 20]
	deleteNode('5'); //[5 10 20]
	printList();
	deleteNode('1');//[5 10]
	printList();
	deleteNode('7');// [10]
	printList();
	deleteNode('2');//[ ] 
	printList();

	deleteNode('2'); //empty list
	return 0;
}

void searchNode(element item)
{
	node *p=head;
	int i=1;
	do
	{
		if(p->data==item)
			break;
		p=p->rlink;
		i++;
	}while(p!=head);
	if(p==head && p->data!=item)
	{
		printf("찾는 노드가 없습니다.\n");
		return;
	}

	printf("찾으시는 노드는 %d 번째 노드입니다.\n",i);
}
void createList()
{
	head==NULL;

}
node *makeNode(element data)
{
	node *newNode = (node*)malloc(sizeof(node));

	newNode->llink= newNode;
	newNode->rlink= newNode;
	newNode->data = data;

	return newNode;
}
void insertNode(node *newNode)
{
	node *p = head;
	if(head==NULL)
	{
		head=newNode;
		return;
	}//공백리스트 인가?
	do
	{
		if(newNode->data < p ->data)
			break;
		p=p->rlink;
	}while(p!=head);
	//newNode 의 뒷노드 (p)탐색
	
	if(p==head && newNode->data < p->data)//첫 노드로 삽입되는 경우
		head=newNode;

	//p:newNode의 뒷노드
	//p->llink:newNode의 앞노드
	newNode->llink=p->llink;
	newNode->rlink=p;

	p->llink->rlink= newNode;
	p->llink= newNode;
}
void printList()
{
	node *p = head;

	if(head==NULL)
	{
		printf("[ ]\n");
		return;
	}
	printf("[ ");
	do
	{
		printf("%c ",p->data);
		p=p->rlink;
	}while(p!=head);

	printf("]\n");
}
void deleteNode(element data)
{
	node *p = head;
	if(head==NULL)
	{
		printf("empty list!!\n");
		return;
	}
	//삭제할노드탐색
	do
	{
		if(p->data == data)
			break;
		p=p->rlink;
	}while(p!=head);

	//하나남은 노드가 삭제되는경우
	if(p==p->rlink && p==p->llink)
	{
		head=NULL;
		free(p);
		return;
	}
	//첫 노드가 삭제되는 경우
	if(p == head && p->data == data)
		head=p->rlink;
	//삭제할 노드가 없는 경우
	if(p==head && p->data !=data)
	{
		printf(" no item!!\n");
		return;
	}
	//p:삭제할 노드
	//p->llink: 앞노드
	//p->rlink: 뒷노드

	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;

	free(p);
}
