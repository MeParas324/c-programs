#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int item)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    if(*head == NULL)
    {
        n->next = NULL;
        *head = n;
    }
    else
    {
        n->next = *head;
       *head = n;
    }
}

void traversal(struct node *head)
{
    while(head!= NULL)
    {
        printf("%d=>", head->data);
        head = head->next;
    }
}

void sort(struct node **head)
{
    struct node *ptr;
    struct node *preptr = NULL;
    int s, temp;
    if(*head == NULL) return ;
    do
    {
        s = 0;
        ptr = *head;

        while (ptr->next != preptr)
        {
            if(ptr->data>ptr->next->data)
            {
                  temp = ptr->data;
                  ptr->data = ptr->next->data;
                  ptr->next->data = temp;
                  s = 1;
            }
            ptr = ptr->next;
        }
        preptr = ptr;
        
        
    } while (s);
    
}

void merge(struct node **head1, struct node **head2)
{
    struct node *ptr = *head1;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = *head2;

}
int main()
{
    int i, n, m, element;
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    printf("Enter the number of elements into the 1 st linked list\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d element you want to insert in 1 st linked list\n", i+1);
        scanf("%d", &element);
        insert(&head1, element);
    }
    printf("\n1 st linked list is\n");
    traversal(head1);
    

    printf("\nEnter the number of elements in 2 nd linked list\n");
    scanf("%d", &m);
    for (i = 0; i<m; i++)
    {
         printf("Enter the %d element you want to insert in 2 st linked list\n", i+1);
         scanf("%d", &element);
         insert(&head2, element);
    }
    printf("\n2 nd linked list is\n");
    traversal(head2);
    
    printf("\n1 st linked list after sorting\n");
    sort(&head1);
    traversal(head1);

    printf("\n2 nd linked list after sorting\n");
    sort(&head2);
    traversal(head2);

    printf("\nMerging both linked list\n");
    merge(&head1, &head2);
    traversal(head1);
    
    printf("\nFinal linked list after sorting\n");
    sort(&head1);
    traversal(head1);

}
