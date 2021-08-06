#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int i, int n){
    int element;

    if(i>n){
        return;
    }
    struct node *nod = (struct node*)malloc(sizeof(struct node));

    printf("Enter %d element:\n", i);
    scanf("%d", &element);
    nod->data = element;

    if(*head == NULL){
        *head = nod;
        (*head)->next = *head;
    }
    else{
       nod->next = *head;
       struct node *ptr = *head;

       while(ptr->next != *head){
           ptr = ptr->next;
       }
       *head = nod;
       ptr->next = *head;
    }
    i++;
    insert(head, i, n);
}

void traversal(struct node *head, struct node *ptr){
    if(head == NULL)
    {
        printf("Circular linked list is empty!\n");
        return ;
    }

    printf("%d-> ", ptr->data);
    if(ptr->next == head){
        return;
    }
    else{
        ptr = ptr->next;
        traversal(head, ptr);
    }

}

int main()
{
    struct node *head = NULL;
    int n;

    printf("Enter the number of elements you want to insert in linked list\n");
    scanf("%d", &n);

    insert(&head, 1, n);
    struct node *ptr = head;
    traversal(head, ptr);
}