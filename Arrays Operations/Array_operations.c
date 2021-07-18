
#include <stdio.h>
#define MAX 10
// insersion
void insert(int *arr, int loc, int ele, int *size)
{
    int i;
        if (arr[loc] == NULL)
                arr[loc] = ele;
        else
        {
                // check current size of array < maximum size of array
                if (*size < MAX)
                {
                        for (i = *size + 1; i > loc; i--)
                        {
                                arr[i] = arr[i - 1];
                        }
                        arr[loc] = ele;
                }
        }
        *size = *size + 1;
}
// traversal
void display(int *arr, int size)
{
    int i;
        for (i = 0; i < size; i++)
        {
                printf("%d ->", arr[i]);
        }
        printf("\n");
}
void delete (int *arr, int loc, int *size)
{
    int i;

        // check current size of array >0
        if (*size > 0)
        {
                for (i = loc; i <= *size + 1; i++)
                {
                        arr[i] = arr[i + 1];
                }
        }
        *size = *size - 1;
}
// searching
int searching(int *arr, int ele, int *size)
{
    int i;

        // check current size of array >0

        for (i = 0; i < *size; i++)
        {
                if (arr[i] == ele)
                        return i;
        }
        return -1;
}
int main()
{
        int arr[MAX];
        int size = 0;
        insert(arr,0,22,&size); // 22
        insert(arr,1,7,&size);  // 22 7
        insert(arr,2,5,&size);  // 22 7 5
        // inserting value between array
        insert(arr,1,2,&size);  // 22 2 7 5
        display(arr,size);        
        delete(arr,1,&size); // 22 7 5
        delete(arr,2,&size); // 22 7
        insert(arr,1,9,&size); // 22 9 7
        insert(arr,2,8,&size); // 22 9 8 7 
        display(arr,size);
}