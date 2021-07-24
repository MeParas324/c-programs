#include <stdio.h>
#include<malloc.h>

int main()
{
    
    int n, i, *ptr, sum = 0;

    printf("\n\nEnter number of elements: ");
    scanf("%d", &n);

    // dynamic memory allocation using malloc()
    ptr = (int*)malloc(n*sizeof(int));

    if(ptr == NULL) // if empty array
    {
        printf("\n\nError! Memory not allocated\n");
        return 0;   // end of program
    }

    printf("\n\nEnter elements of array: \n\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);    
    }

 
    printf("\n\nThe elements of the array are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ",ptr[i]);    
    }

  
    
    return 0;
}