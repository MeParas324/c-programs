#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node* sortedmerge(struct node *a, struct node *b)
{
    struct node *result = NULL;
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    if(a->data <= b->data)
    {
        result = a;
        result ->next = sortedmerge(a->next, b);
    }
    else
    {
        result = b;
        result ->next = sortedmerge(a, b->next);
    }
    return result;
}

void split(struct node *source, struct node **front, struct node **back)
{
    struct node *first;
    struct node *second;
    if (source ==NULL || source->next ==NULL)
    {
        *front = source;
        *back = NULL;
    }
    else
    {
        second = source;
        first = source->next;
        while (first != NULL)
        {
            first = first->next;
            if (first != NULL)
            {
                second = second->next;
                first = first->next;
            }
        }

    *front = source;
    *back = second->next;
    second->next = NULL;
    }
}

void mergesort(struct node **head)
{
    struct node *head_reference = *head;
    struct node *a;
    struct node *b;
    if(head_reference == NULL || head_reference->next == NULL)
    {
        return;
    }
    else
    {
        split(head_reference, &a, &b);
        mergesort(&a);
        mergesort(&b);
        *head = sortedmerge(a, b);
    }
}

void print(struct node *local)
{
    while (local != NULL)
    {
        printf ("%d ", local->data);
        local = local->next;
    }
}

void push(struct node **head, struct node *element)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = *head;
    *head = temp;
}

int main()
{
    int choice, element;
    struct node *start = NULL;

    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Push Element");
		printf("\n\t\t 2. Start Merge sort");
		printf("\n\t\t 3. Display Elements");
		printf("\n\t\t 4. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);
		
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            fflush(stdin);
            scanf("%d", &element);
            push(&start, element);
            break;
        
        case 2:
            mergesort(&start);
            printf("\nList sorted Successfully.");
            break;

        case 3:
            printf("Sorted list is: ");
            print(start);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
    return 0;
}