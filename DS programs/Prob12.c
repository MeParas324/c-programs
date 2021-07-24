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
    
    if ((*rear) == NULL)
    {
        (*front) = newNode;
        (*rear) = (*front);
    }
    else
    {
        (*rear)->next = newNode;
        (*rear) = newNode;
        (*rear)->next= (*front);
    }
    printf("Inserted element is %d", newNode->data);
}

void delete(struct node **front, struct node **rear)
{
    if ((*front) == NULL && (*rear) == NULL)
    {
        printf("Queue is empty.");
    }
    else if ((*front) == (*rear))
    {
        printf("Deleted element is %d", (*front)->data);
        (*front)= (*rear) = NULL;
    }
    else
    {
        printf("Deleted element is %d", (*front)->data);
        (*front) = (*front)->next;
        (*rear)->next = (*front);
    }
}

void display(struct node **front, struct node **rear)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = (*front);
    printf("Elements of Queue are: ");
    if ((*front) == NULL && (*rear) == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        while (temp->next != (*front))
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }       
    printf("\t%d", temp->data);
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
            delete(&front, &rear);
            break;
        
        case 3:
            display(&front, &rear);
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
