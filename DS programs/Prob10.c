#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top,int element)
{
        struct node *newNode;
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = element;
        if (*top == NULL)
        {
            newNode->next= NULL;
        }
        else
        {
            newNode ->next = (*top);
        }
        (*top) = newNode;
        printf("Inserted element is %d", newNode->data);
}

void pop(struct node **top)
{
    if((*top) == NULL)
    {
        printf("Empty Stack.");
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof  (struct node));
        temp = (*top);
        (*top) = (*top)->next;
        printf("Popped element is %d", temp->data);
        free(temp);
    }
}

void display(struct node **top)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = (*top);
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    
}

int main()
{
    struct node *top;
    top = NULL;
    int choice, element;

    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Push Element");
		printf("\n\t\t 2. Pop Element");
		printf("\n\t\t 3. Display Elements");
		printf("\n\t\t 4. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &element);
            push(&top, element);
            break;
        
        case 2:
            pop(&top);
            break;
        
        case 3:
            display(&top);
            break;
        
        case 4:
            return 0;
            break;
        
        default:
            printf("Invalid Option.\n");
            break;
        }
    }
    return 0;
}