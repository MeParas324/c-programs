#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
};

void insert(struct node **head, int element){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = element;
    n->pre = NULL;
    if(*head == NULL){
        n->next = NULL;
        *head = n;
    }
    else{
        n->next = *head;
        n->next->pre = n;
        *head = n;
    }
}

void traversal(struct node *head){

    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
}

void sort(struct node **head){
    int s, temp;
    struct node *ptr;
    struct node *preptr = NULL;
    do{
       s = 0;
       ptr = *head;
       while (ptr->next != preptr)
       {
           if(ptr->data > ptr->next->data){
               temp = ptr->data;
               ptr->data = ptr->next->data;
               ptr->next->data = temp;
               s = 1;
           }
           ptr = ptr->next;
       }
       preptr = ptr;    
    } while (s == 1);
}

void insertAtEnd(struct node **head, int element){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = element;
    n->next = NULL;
    if(*head == NULL){
        n->pre = NULL;
        *head = n;
    }
    else{
        struct node *ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
        n->pre = ptr;
    }
}

void sortMerge(struct node **head1, struct node **head2, struct node **head3){
    struct node *ptr1 = *head1;
    struct node *ptr2 = *head2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data > ptr2->data){
            insertAtEnd(head3, ptr2->data);
            ptr2 = ptr2->next;
        }
        else{
            insertAtEnd(head3, ptr1->data);
            ptr1 = ptr1->next;
        }
    }
    while(ptr1 != NULL){
        insertAtEnd(head3, ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        insertAtEnd(head3, ptr2->data);
        ptr2 = ptr2->next;
    }
}

int main()
{
    int element, n, m, i;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    printf("Enter the number of elements in 1 st linked list\n");
    scanf("%d", &n);
    for(i = 1; i<=n; i++){
        printf("Enter %d element into the linked list\n", i);
        scanf("%d", &element);
        insert(&head1, element);
    }

    printf("Enter the number of elements in 2 st linked list\n");
    scanf("%d", &m);
    for(i = 1; i<=m; i++){
        printf("Enter %d element into the linked list\n", i);
        scanf("%d", &element);
        insert(&head2, element);
    }

    printf("Before Merging and sorting linked lists are\n");
    printf("1st linked list:\n");
    traversal(head1);
    printf("\n2 nd linked list:\n");
    traversal(head2);

    printf("\nAfter sorting 1 st linked list is:\n");
    sort(&head1);
    traversal(head1);

    printf("\nBefore sorting 2 nd linked list is:\n");
    sort(&head2);
    traversal(head2);

    sortMerge(&head1, &head2, &head3);
    printf("\nSorted merged linked list is:\n");
    traversal(head3);


}
