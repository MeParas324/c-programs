#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void display(int *cqueue, int front, int rear);
void del(int *cqueue, int *front, int *rear);
void add(int *cqueue, int *front, int *rear, int item);

int main()
{
	int front = -1, rear = -1, cqueue[MAX];
	int item, choice;
	while(1){
	printf("\n1.Add\n");
	printf("\n2.Del\n");
	printf("\n3.Display\n");
	printf("\n4.Exit\n");
	
	printf("Enter your choice between (1-4):\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("Enter the element you want to insert:\n");
			scanf("%d", &item);
			add(cqueue, &front, &rear, item);
			break;
			
		case 2:
			del(cqueue, &front, &rear);
			break;
			
		case 3:
			display(cqueue, front, rear);
			break;
		
		case 4:
			default:
				printf("Wrong choice\n");
				exit(0);
	}
}
}
void add(int *cqueue, int *front, int *rear, int item){
	
	if((*front == 0 && *rear == MAX - 1) || *front == *rear + 1){
		printf("Cqueue is full!Overflow condition\n");
		return ;
	}
	else{
		if(*front == -1){
			*front = 0;
			*rear = 0;
		}
		else if(*rear == MAX - 1){
			*rear = 0;
		}
		
		else{
			*rear = *rear + 1;
		}
	}
	cqueue[*rear] = item;
	printf("Element you added in cqueue is %d\n", cqueue[*rear]);
}
	
void del(int *cqueue, int *front, int *rear){
	int temp;
	temp = cqueue[*front];
	if(*front == -1){
		printf("Underflow condition\n");
		return ;
	}
	else{
	    if(*front == *rear){
		   *front=*rear=-1;
    	}
    	else if(*front==MAX-1)*front=0;
    	else *front=*front+1;
        }
	printf("Deleted element is %d\n", temp);
}

void display(int *cqueue, int front, int rear){
	
	int i;
	if(front == -1){
		printf("Cqueue is empty!\n");
	}
	else{
		if(front <= rear){
			for(i = front; i<=rear; i++){
				printf("%d ", cqueue[i]);
			}
		}
		
		else{
			for(i = front; i<=MAX - 1; i++){
				printf("%d ", cqueue[i]);
			}
			for(i = 0; i <= rear; i++){
				printf("%d ", cqueue[i]);
			}
		}
	}
}
