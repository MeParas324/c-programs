#include<stdio.h>

int main()
{
    int n, i, j, k;

    printf("Enter the number\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = n; j >= i; j--)
        {
            while (j != i)
            {
                printf(" ");
            }          
        }
        printf("i");
        printf("\n");
        
    }
    
}