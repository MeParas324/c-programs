#include <stdio.h>

void Bsearch(int *arr, int size, int element)
{
    int low = 0, high = size - 1, Mid;

    while (low <= high)
    {
        Mid = (low + high) / 2;
        if (arr[Mid] == element)
        {
            printf("Element %d is found at location %d\n", element, Mid);
            return;
        }
        if (arr[Mid] > element)
        {
            high = Mid - 1;
        }
        else
        {
            low = Mid + 1;
        }
    }
    printf("The element you are searching for is not found\n", element);
}

int main()
{
    int item;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);

    printf("Enter the element you want to search\n");
    scanf("%d", &item);

    Bsearch(arr, size, item);
}