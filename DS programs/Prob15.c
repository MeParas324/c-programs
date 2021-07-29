#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
};

void insert_begining(struct node **start)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    temp->previous = NULL;
    temp->data = element;
    temp->next = (*start);
    (*start) = temp;
}

void delete_end(struct node **start)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if ((*start) == NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *q;
    q= (*start);
    while (q->next->next != NULL)
    {
        q = q->next;
    }
    if (q->next->data != NULL)
    {
        temp = q->next;
        q->next = NULL;
        printf("Deleted element is: %d", temp->data);
        free (temp);
        return;
    }
}

void insert_between(struct node **start)
{
    if((*start) == NULL)
    {
        printf("Can't create Element.");
        printf("Trt inserting in begining.");
        return;
    }
    else
    {
        struct node *temp, *q;
        temp = (struct node*)malloc(sizeof(struct node));
        q= (*start);
        int element, position, i;
        printf("Enter position after which you want to insert: ");
        scanf("%d", &position);
        printf("Enter the element: ");
        scanf("%d", &element);
        temp ->data = element;
        for ( i = 1; i < position; i++)
        {
            q=q->next;
        }
        if (q->next == NULL)
        {
            printf("List too short to insert between.");
            printf("Try Inserting At Begining.");
            return;
        }
        temp->next = q->next;
        q->next->previous = temp;
        q->next = temp;
        temp->previous = q;
    }
}

void delete_first(struct node **start)
{
    if ((*start) == NULL)
    {
    printf("List is empty!");
    return;
    }
    else
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp = (*start);
        (*start) = (*start)-> next;
        (*start)->previous = NULL;
        printf("Deleted element is: %d", temp->data);
        free(temp);
        return;
    }
}

void delete_last(struct node **start)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if ((*start) == NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *q;
    q= (*start);
    while (q->next->next != NULL)
    {
        q = q->next;
    }
    if (q->next->data != NULL)
    {
        temp = q->next;
        q->next = NULL;
        printf("Deleted element is: %d", temp->data);
        free (temp);
        return;
    }
}

void delete_position(struct node **start)
{
    struct node *temp, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = (*start);
    if ((*start) == NULL)
    {
        printf("List is empty!");
        return;
    }
    else
    {
        int position, i;
        printf("Enter the position you want to delete: ");
        fflush(stdin);
        scanf("%d", &position);
        for (i=1; i < position; i++)
        {
            q = temp;
            temp = temp->next;
        }
        q->next = temp->next;
        temp->next->previous = q;
        printf("Deleted element is : %d", temp->data);

        free (temp);
    }
}

void delete_any(struct node **start)
{
    if ((*start) == NULL)
    {
        printf("List is empty!");
        return;
    }
    else
    {
        struct node *temp, *q;
        temp = (struct node*)malloc(sizeof(struct node));
        int element;
        printf("Enter the element you want to delete: ");
        scanf("%d", &element);
        q = (*start);
        if ((*start)->data == element)
        {
            temp = (*start);
            (*start) = (*start)->next;
            printf("%d is deleted.", temp->data);
            free (temp);
            return;
        }
        while (q->next->next != NULL)
        {
            if (q -> next -> data == element)
            {
                temp = q->next;
                temp->next->previous =q;
                q->next = temp->next;
                printf("%d is deleted.", temp->data);
                free (temp);
                return;
            }
            q = q ->next;
        }
    }
    printf("\nElement not found.\n");
}

void display(struct node **start)
{
    if ((*start) == NULL)
    {
        printf("Empty Linked List.");
        return;
    }
    struct node *temp;
    temp = (*start);
    printf("Elements of the linked list are: ");
    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *start;
    start = (struct node*)malloc(sizeof(struct node));
    start = NULL;
    int choice;

    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Insert at begining");
		printf("\n\t\t 2. Delete at end");
		printf("\n\t\t 3. Insert between two nodes");
		printf("\n\t\t 4. Delete First Node ");
		printf("\n\t\t 5. Delete Last Node");
		printf("\n\t\t 6. Delete positon");
		printf("\n\t\t 7. Delete any node");
		printf("\n\t\t 8. Display");
		printf("\n\t\t 9. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            insert_begining(&start);
            break;
        
        case 2:
            delete_end(&start);
            break;
        
        case 3:
            insert_between(&start);
            break;
        
        case 4:
            delete_first(&start);
            break;
        
        case 5:
            delete_last(&start);
            break;
        
        case 6:
            delete_position(&start);
            break;
        
        case 7:
            delete_any(&start);
            break;
        
        case 8:
            display(&start);
            break;
        
        case 9:
            return 0;
            break;
        
        default:
            printf("invalid Input.");
            break;
        }
    }

    return 0;
}
