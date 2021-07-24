#include<stdio.h>

void printarray(int *a, int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
}

void merge(int *a, int low, int mid, int high){
	int i, j, k, m, B[100];
	
	i = low;
	j = mid +1 ;
	k = low;
	
	while(i<=mid && j<=high){
		
		if(a[i]<a[j]){
			B[k] = a[i];
			i++;
			k++;
		}
		else{
			B[k] = a[j];
			j++;
			k++;
		}
    }
		
		while(i<=mid){
			B[k] = a[i];
			i++;
			k++;
		}
		while(j<=high){
			B[k] = a[j];
			j++;
			i++;
		}
      for(m = low; m<=high; m++){
      	a[m] = B[m];
	  }
}

void mergesort(int *a, int low, int high){
	int mid;
	if(low<high){
		mid = (low + high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}




int main()
{
//	int a[] = {9, 1, 4, 14, 4, 15, 6};
    int a[] = {90, 100, 4, 14, 4, 15, 60};
	int n = 7;
	
	printf("Before Merge sort array is...\n");
	printarray(a, n);
	mergesort(a, 0, n-1);
	printf("\nAfter Merge sort array is...\n");
	printarray(a, n);
}