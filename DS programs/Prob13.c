
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

void deleteAtBeg(struct node ** head)
{
	if(*head == NULL)
	{
		printf("No elements are here for delete\n");
		return;
	}
    // store head element in temp
    struct node *temp = *head;
    // point the head pointer to the next element
    *head = (*head)->next;
    // delete temp
    free(temp);
}

void deleteAtEnd(struct node **head)
{
	if(*head == NULL)
	{
		printf("No elements are here for delete\n");
		return;
	}
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

void deletion_At_Pos(struct node **head, int pos)
{
	int i;
    struct node *ptr = *head;
    struct node *temp;
    if(pos == 1)
    {
    	temp = *head;
    	*head = (*head)->next;
	}
	else{
		i = 2;
		while(i<pos)
		{
			if(ptr == NULL) return ;
			ptr = ptr->next;
			i++;
		}
			temp = ptr->next;
			ptr->next = ptr->next->next;
	}
	free(temp);
    
}

void delete_An_Node(struct node **head, int val)
{
	struct node *ptr = *head;
	struct node *temp;
	
	if(ptr->data == val)
	{
		*head = (*head)->next;
		free(ptr);
		return ;
	}
	
	if(*head == NULL)
	{
		printf("No elements are here\n");
    }
    else{
    	while(ptr->next->data != val)
    	{
    		ptr = ptr->next;
    		if(ptr == NULL)
    		{
    			printf("The node you are deleting is not found\n");
    			return ;
			}
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
	}
}


int main()
{
    int element, choice, nod, pos;
    struct node *head = NULL;

    while(1)
    { 
        printf("\n1.Insert at the beginning\n");
        printf("\n2.Insert after a node\n");
        printf("\n3.Deletion of first node\n");
        printf("\n4.Deletion at the end\n");
        printf("\n5.Delete of node whose position is given\n");
        printf("\n6.Delete any node\n");
        printf("\n7.Display linked list\n");
        printf("\n8.Quit the Program\n");
        printf("\nEnter your choice between 1-8\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert at beginning\n");
            scanf("%d", &element);
            insertAtBeg(&head, element);
            break;

        case 2:
            printf("Enter the element to insert after a node\n");
            scanf("%d", &element);
            printf("After which node you want to insert element\n");
            scanf("%d", &nod);
            insertAfterNode(&head, element, nod);
            break;

        case 3:
            deleteAtBeg(&head);
            break;

        case 4:
            deleteAtEnd(&head);
            break;
            
        case 5:
        	printf("Enter which position of node you want to delete\n");
        	scanf("%d", &pos);
        	deletion_At_Pos(&head, pos);
        	break;
        	
        case 6:
            printf("Enter the element of node which you want to delete\n");
            scanf("%d", &nod);
            delete_An_Node(&head, nod);
            break;
        
        case 7:
            printf("Displaying linked list elements\n");
            traversal(head);
            break;
        
        default:
            printf("Quitting the program\n");
            exit(0);
        }
    }
}
