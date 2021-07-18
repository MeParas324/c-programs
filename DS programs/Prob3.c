#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COLUMN 5

void read_array(int x[ROW][COLUMN], int r, int c);
void print_array(int x[ROW][COLUMN], int r, int c);

void addElement(int x[ROW][COLUMN], int r, int c)
{
	int sum = 0, i, j;

	for (i = 0; i < r; i++)
	{
		for (j = 0; i < c; j++)
		{
			sum = sum + x[i][j];
		}
		
	}
	printf("The Sum of all elements is %d\n", sum);
	
}

void addDiagonal(int x[ROW][COLUMN], int r, int c)
{
	int sum = 0, i, j;

	for (i = 0; i < r; i++)
	{
		for (j = 0; i < c; j++)
		{
			if(i == j)
			sum = sum + x[i][j];
		}
		
	}
	printf("The Sum of all Diagonal elements is %d\n", sum);
	
}

void countOdd(int x[ROW][COLUMN], int r, int c)
{
	int odd = 0, i, j;

	for (i = 0; i < r; i++)
	{
		for (j = 0; i < c; j++)
		{
			if(x[i][j]%2 != 0 || x[i][j] == 1)
            odd++;
		}
		
	}
	printf("The Number of odd elements is %d\n", odd);
	
}

void largestNo(int x[ROW][COLUMN], int r, int c)
{
	int large = x[0][0], i, j;

	for (i = 1; i < r; i++)
	{
		for (j = 1; i < c; j++)
		{
			if(x[i][j] >= large)
			large = x[i][j];
		}
		
	}
	printf("Largest number is %d\n", large);
	
}

int main()
{
	int a[ROW][COLUMN];
	int r,c, choice;
	
	printf("Enter the number of rows and columns:\n");
	scanf("%d%d", &r,&c);
	
	read_array(a,r,c);
	print_array(a,r,c);

	while(1)
	{
		printf("\n.1.Add all its elements.\n");
		printf("\n.2.Add all its diagonal.\n");
		printf("\n.3.Count all its odd elements.\n");
		printf("\n.4.Find the largest of all its elements.\n");
		printf("\n.5.Quit.\n");

		printf("Enter your choice:\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			    addElement(a, r, c);
				break;

			case 2:
			    addDiagonal(a, r, c);
				break;
			
			case 3:
			    countOdd(a, r, c);
				break;

			case 4:
			    largestNo(a, r, c);
				break;

			case 5:
			    default:
				    printf("Quitting the program!\n");
					exit(0);
		}


	}

    return 0;
}
void read_array(int x[ROW][COLUMN], int r, int c)
{
	int i,j;
	
	printf("Enter the elements according to %d row and %d columns in array\n", r, c);
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
			scanf("%d",&x[i][j]);
}

void print_array(int x[ROW][COLUMN], int r, int c)
{
	int i,j;
	
	printf("Printing the elements according to %d row and %d columns in array\n", r, c);
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
			printf("%d ",x[i][j]);
			   
			   printf("\n");
	}
}
