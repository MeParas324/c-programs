#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;

void push(Node **head, int element){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = element;
    if(*head == NULL){
        n->next = *head;
        *head = n;
    }
    else{
        n->next = *head;
        *head = n;
    }
}

void pop(Node **head){
    if(*head == NULL){
        printf("Stack underflow\n");
        return;
    }
    else{
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void display(Node *head){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
}

int main()
{
    int choice, element;
    Node *top = NULL;

    while(1){
        printf("\n\t\t=====Stack linked list Menu\n");
        printf("\n\t\t1.Push element\n");
        printf("\n\t\t2.Pop element\n");
        printf("\n\t\t3.Peek\n");
        printf("\n\t\t4.Display elements\n");
        printf("\n\t\t5.Quit\n");

        printf("\n\t\tEnter your choice\n");
        scanf("%d", &choice);

        switch(choice){
            
            case 1:
                printf("Enter the element you want to push\n");
                scanf("%d", &element);
                push(&top, element);
                break;

            case 2:
                printf("Popping the element\n");
                pop(&top);
                break;

            case 3:
                printf("Peek is %d", top->data);
                break;

            case 4:
                printf("Displaying all the elements\n");
                display(top);
                break;

            case 5:
                printf("Quitting the program\n");
                return 0;
            
            default:
                printf("Invalid input");
                return 0;

        }
    }
}