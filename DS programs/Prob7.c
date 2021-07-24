#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int display(int *s, int top);
int pop(int *s, int top);
int push(int *s, int top, int item);

int main()
{
	int stack[MAX], choice, item, top = -1;
	
	while(1){
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		
		printf("ENter your choice\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter the number your want to push\n");
				scanf("%d", &item);
				top = push(stack, top, item);
				break;
	        
	        case 2:
	        	top = pop(stack, top);
	        	break;
	        	
	        case 3:
	        	display(stack, top);
	        	break;
	        	
	        case 4:
	        	default:
	        		printf("Wrong choice\n");
	        		exit(0);
		}
	}
}

int push(int *s, int top, int item)
{
	if(top == MAX -1){
		printf("Stack overflow\n");
		//return 0;
	}
	else{
		top = top + 1;
		s[top] = item;
		printf("The element your pushed is %d\n", s[top]);
	}
return top;
}

int pop(int *s, int top){
	int temp_var;
	if(top == -1)
	{
		printf("Stack is empty\n");
		//return 0;
	}
	else{
		temp_var = s[top];
		printf("The element you deleted is %d\n", temp_var);
		top = top - 1;
	}
return top;
}

int display(int *s, int top){
	int i;
	if(top == -1){
		printf("Stack is empty\n");
		//return 0;
	}
	else{
		for(i = top; i>=0; i--)
		{
			printf("%d ", s[i]);
		}
	}
}