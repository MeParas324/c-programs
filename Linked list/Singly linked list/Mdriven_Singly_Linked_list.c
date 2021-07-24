#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertAtBeg(struct node **head, int item)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    if(*head == NULL)
    {
         n->next = NULL;
         *head = n;
    }
    else{
        n->next = *head;
        *head = n;
    }
}

void traversal(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d=>", head->data);
        head = head->next;
    }
}

void insertAtEnd(struct node **head, int item)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
    } else {
        struct node *ptr = *head;
        // moving ptr to the last node
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = n;
    }
}

void insertAfterNode(struct node **head, int data, int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    struct node* ptr = *head;

    while (ptr->data != val)
        ptr = ptr->next;

    n->next = ptr->next;
    ptr->next = n;

}

void insertBeforeNode(struct node **head, int data, int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    struct node* ptr = *head;

    if ((*head)->data == val)
    {
        n->next = *head;
        *head = n;
    }
    else {
       while(ptr->next->data != val)
        {
        ptr = ptr-> next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}

void deleteAtBeg(struct node ** head)
{
    // store head element in temp
    struct node *temp = *head;
    // point the head pointer to the next element
    *head = (*head)->next;
    // delete temp
    free(temp);
}

void deleteAtEnd(struct node ** head)
{
    struct node *ptr = *head, *temp;
    if ((*head)->next == NULL)
    {
        temp = *head;
        *head = NULL;
        free(temp);
    } 
    else {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
}

void deleteAfterNode(struct node **head, int val)
{
    struct node *ptr = *head, *temp;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);

}

void deleteBeforeNode(struct node **head, int val)
{
    struct node *ptr = *head, *temp;
    if (ptr->next->data == val)
    {
        temp = *head;
        *head = (*head)->next;
    }
    else
    {
        while (ptr->next->next->data != val)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = ptr->next->next;
    }
    free(temp);
}

void search(struct node *head, int element)
{
    int pos;
    while(head !=NULL)
    {
    	if(head->data == element){
    		pos++;
            printf("Element is found at location %d\n", pos);
			return ;		
		}
        head = head->next;
        pos++;
    }
    printf("Element is not found\n");

}



int main()
{
    int n, i, element, choice, nod;
    struct node *head = NULL;

    while(1)
    { 
        printf("\n1.Insert at the beginning\n");
        printf("\n2.Insert at the end\n");
        printf("\n3.Insert after a node\n");
        printf("\n4.Insert before a node\n");
        printf("\n5.Delete at the beginning\n");
        printf("\n6.Delete at the end\n");
        printf("\n7.Delete after a node\n");
        printf("\n8.Delete before a node\n");
        printf("\n9.Searching for an element\n");
        printf("\n10.Traversing in a linked list\n");
        printf("\n11.Quit the Program\n");
        printf("\nEnter your choice between 1-11\n");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Enter the element to insert after a node\n");
            scanf("%d", &element);
            printf("After which node you want to insert element\n");
            scanf("%d", &nod);
            insertAfterNode(&head, element, nod);
            break;

        case 4:
            printf("Enter the element to before  a node\n");
            scanf("%d", &element);
            printf("Before which node you want to insert element\n");
            scanf("%d", &nod);
            insertBeforeNode(&head, element, nod);
            break;

        case 5:
            deleteAtBeg(&head);
            break;

        case 6:
            deleteAtEnd(&head);
            break;

        case 7:
            printf("After which node you want to delete element\n");
            scanf("%d", &nod);
            deleteAfterNode(&head, nod);
            break;

        case 8:
            printf("Before which node you want to delete element\n");
            scanf("%d", &nod);
            deleteBeforeNode(&head, nod);
            break;

        case 9:
            printf("Enter an element you want to search\n");
            scanf("%d", &element);
            search(head, element);
            break;
        
        case 10:
            printf("Displaying linked list elements\n");
            traversal(head);
            break;
        
        default:
            printf("Quitting the program\n");
            exit(0);
        }



    }

}