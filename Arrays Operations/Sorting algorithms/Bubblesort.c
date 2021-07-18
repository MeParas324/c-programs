#include<stdio.h>
void printarray(int *A, int n);
void bubblesort(int *A, int n);

int main(){
	
	int arr[5] = {23, 5, 8, 6, 56};
    int size = 5;
    
    printf("Printing elements before sorting...\n");
    printarray(arr, size);
    bubblesort(arr, size);
    printf("Printing elements after sorting...\n");
    printarray(arr, size);
}

void printarray(int *A, int n){
	
	int i;
	for(i = 0; i<=n-1; i++){
		printf("%d ", A[i]);
	}
	
	printf("\n");
}

void bubblesort(int *A, int n){
	
	 
	int i, j, temp;
	for(i = 0; i<n-1; i++){
		
		for(j = 0; j<n-1-i; j++){
			
			if(A[j]>A[j+1]){
			temp = A[j];
			A[j]= A[j+1];
			A[j+1] = temp;
		    }
		}
	}
	printf("\n");
}
