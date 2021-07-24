#include<stdio.h>

void print_Array(int array[], int size)
{
    for (int i =0; i <size ; i++)
    {
        printf("%d ", array[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[high];
    int i = low -1;
    for (int j = low; j<high; j++)
    {
        if (arr[j]<= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i +1], &arr[high]);
    return(i+1);
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int part= partition (arr, low, high);
        quick_sort(arr, low, part-1);
        quick_sort(arr, part +1, high);
    }
}
int main()
{
    int arr[] = {4, 6, 2, 3, 8, 9, 5, 1, 7};
    int length = sizeof(arr)/ sizeof(arr[0]);

    printf("Unsorted Array is: ");
    printf("\n");
    print_Array(arr, length);

    quick_sort(arr, 0, length-1);
    printf("\nSorted array in ascending order: ");
    printf("\n");
    print_Array(arr, length);
}