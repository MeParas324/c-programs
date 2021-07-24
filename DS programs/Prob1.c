#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, n;
	int *ptr;
	ptr=(int*) malloc(n*sizeof(int));

    printf("Enter the number of elements into the array:\n");
    scanf("%d", &n);
    
    printf("Enter %d elements into the array:\n", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ptr[i]);
	}

    printf("Printing the elements you entered into the array\n");
	for(i=0; i<n; i++)
	{
		printf("%d \n", ptr[i]);
	
	}
	
	return 0;
	
	
}
