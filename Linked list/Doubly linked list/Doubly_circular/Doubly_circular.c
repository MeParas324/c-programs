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
    if(*head == NULL){
        n->next = n;
        n->pre = n;
        *head = n;
    }
    else{
        struct node *ptr = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        n->next = *head;
        n->next->pre = n;
        ptr->next = n;
        n->pre = ptr;
        *head = n;
    }
}

void insertAtEnd(struct node **head, int element){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = element;
    if(*head == NULL){
        n->pre = n;
        n->next = n;
        *head = n;
    }
    else{
        struct node *ptr = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = n;
        ptr->next->pre = ptr;
        n->next = *head;
        (*head)->pre = n;
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
            while(ptr->data != nod && ptr->next != *head){
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
            while(ptr->next->data != nod && ptr->next != *head){
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
    struct node *ptr = head;
   do{
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }while(ptr->next != head);
}

void deleteAtBeg(struct node **head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(*head == NULL){
        printf("List is empty!Cannot delete.\n");
        return;
    }
    if((*head)->next == *head){
        struct node*ptr = *head;
        *head = NULL;
        free(ptr);
    }
    else{
        struct node *ptr = *head;
        *head = (*head)->next;
        temp = ptr;
        while(temp->next != ptr){
            temp = temp->next;
        }
        temp->next = *head;
        (*head)->pre = temp;
        free(ptr);
    }
}

void deleteAtEnd(struct node **head){
    struct node *ptr = *head;
    struct node *temp;
    if((*head) == NULL){
        printf("List is empty!Cannot delete.\n");
        return;
    }
    if((*head)->next == *head){
        deleteAtBeg(head);
    }
    else{
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        temp = ptr->pre;
        temp->next = ptr->next;
        temp->next->pre = temp;
        free(ptr);
    }
}

void deleteAfterNode(struct node **head, int nod){
    struct node *ptr = *head;
    struct node *temp;
    if(*head == NULL){
        printf("List is empty!Cannot delete.\n");
        return;
    }
    if(ptr->data == nod && ptr->next != *head){
        ptr = ptr->next;
        (*head)->next = (*head)->next->next;
        (*head)->next->next->pre = (*head);
        free(ptr);
    }
    if(ptr->data == nod){
        ptr = ptr->next;
        (*head)->next = *head;
        (*head)->pre = *head;
        free(ptr);
    }
    else{
       while(ptr->data != nod && ptr->next != *head){
           ptr = ptr->next;
       }
       if(ptr->data != nod){
           printf("Node is not found\n");
           return;
       }
       if(ptr->data == nod && ptr->next == *head){
           printf("You want to delete a node after the last node which is not possible\n");
           return;
       }
       temp = ptr->next;
       ptr->next = ptr->next->next;
       ptr->next->pre = ptr;
       free(temp);
    }
}

void deleteAtBefore(struct node **head, int nod){
    struct node *ptr = *head;
    struct node *temp;
    if(*head == NULL){
        printf("List is empty!Cannot delete.\n");
        return;
    }
    if((*head)->data == nod){
        printf("You cannot delete any node before 1 st node\n");
        return;
    }
    if((*head)->next->data == nod){
        deleteAtBeg(head);
    }
    else{
       while(ptr->next->data != nod){
           ptr = ptr->next;
           if(ptr->next == *head){
               printf("Node is not found\n");
               return;
           }
         }
       if(ptr->next != *head)
       {
       temp = ptr->pre;
       temp->next = ptr->next;
       ptr->next->pre = temp;
       free(ptr);
       }
    }
}

void search(struct node *head, int element){
    int location = 1;
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    while(head->data != element && head->next != head){
        head = head->next;
        location++;
    }
    if(head->data != element){
        printf("Element %d is not found\n", element);
        return ;
    }
    printf("Element %d is found at location %d\n", element, location);
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
    printf("\n5.Deletion at beginning\n");
    printf("\n6.Deletion at end\n");
    printf("\n7.Deletion after a node\n");
    printf("\n8.Deletion before a node\n");
    printf("\n9.Displaying all elements\n");
    printf("\n10.Searching an element\n");
    printf("\n11.Quit\n");

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
           printf("Deleting at beginning\n");
           deleteAtBeg(&head);
           break;

        case 6:
           printf("Deleting at end\n");
           deleteAtEnd(&head);
           break;

        case 7:
           printf("Enter the node after you want to delete a node\n");
           scanf("%d", &nod);
           deleteAfterNode(&head, nod);
           break;

        case 8:
           printf("Enter the node before you want to delete a node\n");
           scanf("%d", &nod);
           deleteAtBefore(&head, nod);
           break;

        case 9:
           printf("Displaying all elements\n");
           display(head);
           break;

        case 10:
           printf("Search an element\n");
           scanf("%d", &element);
           search(head, element);
           break;

        case 11:
           printf("Quitting the program\n");
           return 0;
        
        case 12:
           default:
              printf("Invalid input\n");
              return 0;

    }

    }
}