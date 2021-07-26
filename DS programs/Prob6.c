#include<stdio.h>

int insert(int *array)
{
	int num, i;
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	for (i=0; i<num ; i++)
	{
		printf("Enter %d element: ", i+1);
		fflush(stdin);
		scanf("%d", &array[i]);
	}
	return i;
}

void display(int *array, int length)
{
	if (array[0] == NULL)
	{
		printf("Empty array.");
	}
	else
	{
		int i;
		printf("Elements are: ");
		for (i=0; i<length;i++)
		{
			printf("%d", *(array + i));
		}
	}
}

int input_element(int *array, int last, int element)
{
	array[last]= element;
	last++;
	return last;
}

int delete_element(int *array, int last)
{
	if (array[0] == 0)
	{
		printf("Empty Array.");
		return;
	}
	else
	{
	last= last -1;
	printf("Deleted element is: %d", array[last]);
	return last;
	}
}

void sort_ascending(int *array, int last)
{
	int i, j;
	int temp;
	for (i=0; i<last; i++)
	{
		for (j=i+1; j<last; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("\n Array sorted in Ascending Order Successfully.\n");
}

void sort_descending(int *array, int last)
{
	int i, j;
	int temp;
	for (i=0; i<last; i++)
	{
		for (j=i+1; j<last; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("\n Array sorted in Descending Order Successfully.\n");
}

int main()
{
	int array[10];
	int choice, element;
	array[0] = NULL;
	int last=0;
	
	while(1)
    {
        printf("\n\t     ==========MENU==========");
		printf("\n\t\t 1. Input Array");
		printf("\n\t\t 2. Output/Display Elements");
        printf("\n\t\t 3. Insert an Element");
        printf("\n\t\t 4. Delete an Element");
        printf("\n\t\t 5. Sort Array in Ascending Order");
        printf("\n\t\t 6. Sort Array in Descending Order");
		printf("\n\t\t 7. Exit");
		
		printf("\nEnter Choice Number: ");
		scanf("%d", &choice);
		
		switch(choice)
        {
            case 1:
                last = insert(&array[0]);
                break;
	        	
            case 2:
	        	display(array, last);
                break;
	        	
			case 3:
				printf("\nEnter Element to push: ");
				scanf("%d", &element);
				last = input_element(&array[0], last, element);
				break;
	        
	        case 4:
				last = delete_element(&array[0], last);
	        	break;

            case 5:
                sort_ascending(&array[0], last);
                break;

            case 6:
                sort_descending(&array[0], last);
                break;
	        	
	        case 7:
	        	return 0;

	        default:
	    		printf("\nInvalid option.");
		}
	}

    return 0;
}
