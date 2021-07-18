#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *Head = NULL;

void insert(int item){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = item;

    if(Head == NULL)
    {
        n->next = NULL;
        Head = n;
    }
    else{
        n->next = Head;
        Head = n;
    }
	
}

void Traversal()
{
	struct node *p = Head;
	
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}


void odd()
{
	struct node *p = Head;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next->next;
	}
	
}

void even()
{
	struct node *q = Head->next;
	while(q != NULL)
	{
		printf("%d ", q->data);
		q = q->next->next;
	}
}




int main()
{
	int i ,element, j;
	printf("Enter how many elements you want to enter in linked list:\n");
	scanf("%d", &i);
	
    for(j =0; j<i; j++){
    	printf("Enter the %d element to linked list ", j + 1);
    	scanf("%d", &element);
    	insert(element);
	}
	
	printf("Normal linked list:\n");
	Traversal();
	
	printf("\nAfter dividing Normal linked list the Odd linked list is:\n");
	even();

	printf("\nAfter dividing Normal linked list the Even linked list is:\n");
    odd();
	
}