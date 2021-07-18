#include<stdio.h>

void fibonacci(int a);
int main()
{
	int a;
	
	printf("Enter the number of terms:\n");
	scanf("%d", &a);
	
	fibonacci(a);
}

void fibonacci(int a){
	int first = 0;
	int second = 1;
	int next, i;
	
	printf("Fibonacci series : %d %d ", first, second);
	for(i = 3; i <= a; i++){
		next = first + second;
		first = second;
		second = next;
		
		printf("%d ", next);
	}
	
}