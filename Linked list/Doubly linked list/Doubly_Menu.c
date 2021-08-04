#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
};

void insertAtBeg(struct node **head, int element)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = element;
    n->pre = NULL;
    if(*head == NULL){
        n->next = NULL;
        *head = n;
    }
    else{
        n->next = *head;
        *head = n;
    }
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

void insertAfterNode(struct node **head, int nod, int val){
    if(*head == NULL){
        printf("For insert after atleast 1 element must be available in linked list\n");
        return ;
    }
    else{
        struct node *ptr = *head;
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = val;

        if(ptr->data == nod){
            n->next = ptr->next;
            ptr->next = n;
            ptr->next->pre = ptr;
            n->next->pre = n;
        }
        else{
            while(ptr->data != nod && ptr->next != NULL){
                ptr = ptr->next;
            }
            if(ptr->data != nod){
                printf("Node is not found\n");
                return;
            }
            n->next = ptr->next;
            ptr->next = n;
            n->pre = ptr;
        }
    }
}

void insertBeforeNode(struct node **head, int nod, int val){
    if(*head == NULL){
        printf("For insert after atleast 1 element must be available in linked list\n");
        return ;
    }
    else{
        struct node *ptr = *head;
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = val;

        if(ptr->data == nod){
            insertAtBeg(head, val);
        }
        else{
            while(ptr->next->data != nod && ptr->next != NULL){
                ptr = ptr->next;
            }
            if(ptr->next->data != nod){
                printf("Node is not found\n");
                return ;
            }
            n->next = ptr->next;
            ptr->next = n;
            n->pre = ptr;
            n->next->pre = n;

        }
    }
}

void display(struct node *head){
    if(head == NULL){
        printf("Linked list is empty\n");
        return ;
    }
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
}

int main()
{
    int choice, element, nod;
    struct node *head = NULL;

    while(1){
    printf("\n======Stack menu======\n");
    printf("\n1.Insertion at beginning\n");
    printf("\n2.Insertion at end\n");
    printf("\n3.Insertion after a node\n");
    printf("\n4.Insertion before a node\n");
    printf("\n5.Displaying all elements\n");
    printf("\n6.Quit\n");

    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch(choice){
        
        case 1:
           printf("Enter the element you want to insert at beginning\n");
           scanf("%d", &element);
           insertAtBeg(&head, element);
           break;

        case 2:
           printf("Enter the element you want to insert at end\n");
           scanf("%d", &element);
           insertAtEnd(&head, element);
           break;

        case 3:
           printf("Enter the element you want to insert after the node\n");
           scanf("%d", &element);
           printf("After which node you want to insert element\n");
           scanf("%d", &nod);
           insertAfterNode(&head, nod, element);
           break;

        case 4:
           printf("Enter the element you want to insert before a node\n");
           scanf("%d", &element);
           printf("Before which node you want to insert element\n");
           scanf("%d", &nod);
           insertBeforeNode(&head, nod, element);
           break;

        case 5:
           printf("Displaying the elements\n");
           display(head);
           break;

        case 6:
           printf("Quitting the program\n");
           return 0;

        default:
           printf("Invalid input\n");
           break;

    }

    }
}
