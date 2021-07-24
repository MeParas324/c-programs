#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void add(int *queue, int *rear, int *front, int item)
{
    if(*rear == MAX - 1)
    {
        printf("Queue Overflow!You cannot enter the element\n");
    }
    else
    {
        if(*front == -1)
        {
            *front = 0;
        }
        *rear = *rear + 1;
        queue[*rear] = item;
        printf("Element you added is %d\n", queue[*rear]);
    }
    
}

void delete(int *queue, int *rear, int *front)
{
    int temp;
    if(*front == -1)
    {
        printf("Queue underflow! Queue is empty!\n");
        return ;
    }
    temp = queue[*front];
    if(*front == *rear)
    {
        *front = *rear = -1;
    }
    else{
        *front = *front + 1;
    }
    printf("Element you deleted is %d\n", temp);
}

void display(int *queue, int rear, int front)
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty!\n");
        return ;
    }
    else
    {
        printf("Queue is as follows\n");
        for(i = front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }

    }
    
}
int main()
{
    int rear = -1;
    int front = -1;
    int queue[MAX];
    int ch, item;

    while(1)
    {
        printf("\nEnter your choice between 1-4\n");
        printf("\n1.Add\n");
        printf("\n2.Delete\n");
        printf("\n3.Display\n");
        printf("\n4.Quit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element you want to Add in queue\n");
            scanf("%d", &item);
            add(queue, &rear, &front, item);
            break;
        
        case 2:
            delete(queue, &rear, &front);
            break;

        case 3:
            display(queue, rear, front);
            break;
        
        default:
            printf("Quitting the program\n");
            exit(0);
        }
    }
    return 0;
}