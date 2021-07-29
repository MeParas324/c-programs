#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertAtAfter(struct node**head, int val, int data)
{
	struct node *new_element = (struct node *)malloc(sizeof(struct node));
	new_element->data = data;
	struct node* ptr = *head;
	while (ptr->data != val && ptr->next != *head)
	{
		ptr = ptr->next;
	}
	if (ptr->data != val)
		return;
	new_element->next = ptr->next;
	ptr->next = new_element;
}


void insertAtBeg(struct node **head, int element)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = element;
	if (*head == NULL)
	{
		*head = n;
		(*head)->next = *head;

	}
	else
	{
		struct node *ptr = *head;
		n->next = *head;
		while (ptr->next != *head)
			ptr = ptr->next;

		ptr->next = n;
		*head = n;
	}
}


void deleteAtBeg(struct node **head)
{
	struct node *ptr = *head;
	struct node *temp = *head;
	if (*head == NULL) {
		printf("Linked list is empty!Cannot delete element\n");
		return ;
	}
	while (ptr->next != *head) {
		ptr = ptr->next;
	}
	*head = (*head)->next;
	free(temp);
	ptr->next = *head;

}

void deleteAtEnd(struct node **head) {
	struct node *ptr = *head;
	struct node *temp;
	if (*head == NULL) {
		printf("Circular linked list is empty\n");
		return ;
	}
	if (ptr->next == *head) {
		temp = ptr;
		free(temp);
		*head = NULL;
	}

	else {
		while (ptr->next->next != *head) {
			ptr = ptr->next;
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
		free(temp);
	}
}

void traversal(struct node *head)
{
	struct node *ptr = head;
	if (ptr == NULL)
	{
		printf("Circular linked list empty\n");
	}
	else {
		do {
			printf("%d ", ptr->data);
			ptr = ptr->next;
		} while (ptr != head);
	}
}

void deleteAtPos(struct node **head, int pos)
{
	int i;
	struct node *ptr = *head;
	struct node *temp;
	if (*head == NULL) {
		printf("\nNo elements are here\n");
		return;
	}
	if (pos == 1)
	{
		deleteAtBeg(head);
	}
	else {
		i = 2;
		while (i < pos)
		{
			if (ptr->next == *head) return ;
			ptr = ptr->next;
			i++;
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
		free(temp);
	}
}


void deleteANode(struct node **head, int val)
{
	struct node *ptr = *head;
	struct node *temp;

	if (ptr->data == val)
	{
		*head = (*head)->next;
		free(ptr);
		return ;
	}

	if (*head == NULL)
	{
		printf("No elements are here\n");
	}
	else {
		while (ptr->next->data != val)
		{
			ptr = ptr->next;
			if (ptr == *head)
			{
				printf("The node you are deleting is not found\n");
				return ;
			}
		}
		temp = ptr->next;
		ptr->next = ptr->next->next;
		free(temp);
	}
}


int main()
{
	int choice, nod, element, pos;
	struct node *head = NULL;

	while (1)
	{
		printf("\n1.Insertion at beginning:");
		printf("\n2.Deletion at end:");
		printf("\n3.Insertion after node:");
		printf("\n4.Deletion at beginning:");
		printf("\n5.Deletion at end node:");
		printf("\n6.Deletion of a node whose position is given:");
		printf("\n7.Deletion of any node:");
		printf("\n8.Display:");
		printf("\n9.Quit:");

		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			printf("\nEnter the element you want to insert at beginning:");
			scanf("%d", &element);
			insertAtBeg(&head, element);
			break;

		case 2:
			printf("Deletion at ending:\n");
			deleteAtEnd(&head);
			break;

		case 3:
			printf("\nEnter the number you want to insert after a node:");
			scanf("%d", &element);
			printf("Enter the value of node you want to insert element after:");
			scanf("%d", &nod);
			insertAtAfter(&head, nod, element);
			break;

		case 4:
			printf("\nDeletion of beginning element:");
			deleteAtBeg(&head);
			break;

		case 5:
			printf("\nDeletion of last element:");
			deleteAtEnd(&head);
			break;

		case 6: {
			printf("Enter the position of node which you want to delete\n");
			scanf("%d", &pos);
			deleteAtPos(&head, pos);
			break;
		}

		case 7: {
			printf("\nEnter the node which you want to delete\n");
			scanf("%d", &nod);
			deleteANode(&head, nod);
			break;
		}

		case 8:
			printf("\nDisplaying all elements of Circular linked list\n");
			traversal(head);
			break;

		default:
			printf("Quitting the program\n");
			exit(0);

		}
	}


}
