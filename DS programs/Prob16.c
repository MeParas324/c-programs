#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **Head, int item)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    
    // if(*Head == NULL)
    // {
    //     n->next = *Head;
    //     *Head = n
    // }
    n->next = *Head;
    *Head = n;

}

void traversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
}

void is_even_odd(struct node *Head, struct node **p, struct node **q)
{
     int isodd = 1;

     while(Head != NULL)
     {
         if(isodd == 1)
         {
            insert(p, Head->data);
            isodd = 0;
         }
         else
         {
             {
                 insert(q, Head->data);
                 isodd = 1;
             }
         }
         Head = Head->next;
     }
}



int main()
{
    int num, element, i;

    struct node *Head = NULL;
    struct node *odd = NULL;
    struct node *even = NULL;

    printf("Enter how many elements you want to enter in linked list:\n");
    scanf("%d", &num);

    for(i = 1; i<=num; i++)
    {
        printf("Enter %d number into the linked list\n", i);
        scanf("%d", &element);
        insert(&Head, element);
    }

    printf("Before dividing linked list elements are:\n");
    traversal(Head);

    is_even_odd(Head, &odd, &even);

    printf("\nOdd linked list is..\n");
    traversal(odd);

    printf("\nEven linked list is..\n");
    traversal(even);

}