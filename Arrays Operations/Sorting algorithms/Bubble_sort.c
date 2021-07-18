#include<stdio.h>
void printarray(int *arr, int size){
	
	int i;
	for(i = 0; i<= size-1; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}

void bubblesort(int *arr, int size){
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

int main()
{
    int i;
    int arr[7] = {3, 9, 3, 2, 90, 21, 7};

    bubblesort(arr, 7);

    printarray(arr, 7);
    

}