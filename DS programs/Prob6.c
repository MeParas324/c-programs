#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void ascendingSort(int *arr, int size){
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] >= arr[j + 1])
            {
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1]= temp;
            }
        }
    }
}

void descendingSort(int *arr, int size){
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] <= arr[j + 1])
            {
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1]= temp;
            }
        }
    }
}

int main()
{
    int arr[MAX] = {0};
    int ch, item, n, i, j, k, l;

    while (1)
    {
        printf("\n.1.Input elements\n");
        printf("\n.2.Output elements\n");
        printf("\n.3.Sorting elements in ascending order\n");
        printf("\n.4.Sorting elements in decending order\n");
        printf("\n.1.Quit\n");
        
        printf("Enter your choice between 1-5\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
             printf("Enter the no of elements into the array");
             scanf("%d", &n);
             for (i = 0; i < n; i++)
             {
                 scanf("%d", &arr[i]);
             }
             break;

        case 2:
             for (j = 0; j < MAX; j++)
             {
                 printf("%d ", arr[j]);
             }
             if(j == MAX){
                 printf("Array is empty pleszz insert elements by choosing option 1\n");
                 break;
             }
             
             printf("Printing the elements of the array\n");
             for (i = 0; i < n; i++)
             {
                 printf("%d ", arr[i]);
             }
             break;
        
        case 3:
             for (k = 0; k < MAX; k++)
             {
                 printf("%d ", arr[k]);
             }
             if(k == MAX){
                 printf("Array is empty pleszz insert elements first\n");
                 break;
             }
             ascendingSort(arr,n);
             break;
            
        case 4:
             for (l = 0; l < MAX; l++)
             {
                 printf("%d ", arr[l]);
             }
             if(l == MAX){
                 printf("Array is empty pleszz insert elements by choosing option 1\n");
                 break;
             }
             descendingSort(arr,n);
             break;

        case 5:
             default:
                 printf("Quitting the program\n");
                 exit(0);
    
        }
    }
    
}