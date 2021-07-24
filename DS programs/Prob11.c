#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add(struct node **front, struct node **rear, int element)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->next = NULL;
    
    if ((*front) == NULL)
    {
        (*front) = newNode;
        (*rear) = (*front);
    }
    else
    {
        (*rear)->next = newNode;
        (*rear) = newNode;
    }
    printf("Inserted element is %d", newNode->data);
}

void delete(struct node **front)
{
    if ((*front) == NULL)
    {
        printf("Queue is empty.");
    }
    else if ((*front) != NULL)
    {
        printf("Deleted element is %d", (*front)->data);
        (*front)= (*front)->next;
    }
}

void display(struct node **front)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = (*front);
    if ((*front) == NULL)
    {
        printf("Queue is empty");
    }

    else if ((*front) != NULL)
    {
        printf("Elements are: ");
        while (temp != NULL)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
    printf("\n");
    }
}

int main()
{
    struct node *front;
    struct node *rear;
    front = NULL;
    rear = NULL;
    int choice, element;

    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Add Element");
		printf("\n\t\t 2. delete Element");
		printf("\n\t\t 3. Display Elements");
		printf("\n\t\t 4. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &element);
            add(&front, &rear, element);
            break;
        
        case 2:
            delete(&front);
            break;
        
        case 3:
            display(&front);
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
