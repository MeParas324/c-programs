#include<stdio.h>

int main()
{
    int i, j, n;

    printf("Enter the number:\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n ; j++)
        {
            if(j>=i)
            {
            printf("%d", j);
            }

            else if(j<i)
            {
                printf(" ");
            }
            
        }

        printf("\n");
        
    }
    
}