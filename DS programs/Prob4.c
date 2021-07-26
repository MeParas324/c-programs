#include<stdio.h>
#define R 3
#define C 3
void multiply_array(int x[R][C], int y[R][C], int z[R][C]);


int main()
{

	int a[R][C] = {{3, 6, 8},
	               {4, 8, 2},
				   {6, 3, 1}};

    int b[R][C] = {{4, 6, 8},
	               {4, 2, 6},
				   {6, 3, 1}};

	int s[R][C];
	
	printf("The Multiplication of Array A and B:\n");
	multiply_array(a, b, s);
	
	return 0;
	
}


void multiply_array(int x[R][C], int y[R][C], int z[R][C])
{
	int i,j;
	for(i=0; i<R; i++)
	{
	  for(j=0; j<C; j++)
	  {
	    z[i][j] = x[i][j] * y[i][j];
	    printf("%d ", z[i][j]);
	  }
	  printf("\n");
	}
}
