#include<stdio.h>
#define MAX 5

int main()
{
    int arr[MAX];
    int front = -1;
    int rear = -1;
    int choice, element, i;
    while (1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Add Element");
		printf("\n\t\t 2. Delete Element");
		printf("\n\t\t 3. Display Elements");
		printf("\n\t\t 4. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if ((rear == MAX-1 && front == 0) || (front == rear +1))
            {
                printf("Queue is Full");
            }
            else
            {
                if (front == -1)
                {
                    front =0;
                    rear =0;
                }
                else if (rear == MAX -1)
                {
                    rear = 0;
                }
                else
                {
                    rear = rear +1;
                }
                printf("Enter the number to insert: ");
                scanf("%d", &arr[rear]);
                
            }
            break;
        case 2:
        if (front == -1)
        {
            printf ("Queue is empty");
        }
        else
        {
            printf("Deleted element is : %d", arr[front]);
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                if (front == MAX -1)
                {
                    front = 0;
                }
                else
                {
                    front = front +1;
                }
            }
        }
            break;
        case 3:
            printf("Queue elements are: ");
            if (front == -1)
            {
                printf("Queue is empty.");
            }
            else if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                {
                    printf("%d\t", arr[i]);
                }
                printf("\n");
            }
            else
            {
                for (i=front; i<=MAX -1; i++)
                {
                    printf("%d\t", arr[i]);
                }
                for (i=0; i<=rear; i++)
                {
                    printf("%d\t", arr[i]);
                }
                
            }
            break;
        case 4:
            return 0;
            break;
        
        default:
        printf("Invalid Option.");
            break;
        }
    }
    return 0;
}
