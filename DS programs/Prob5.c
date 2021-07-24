#include<stdio.h>
int factorial(int n);

int main()
{
    int n, a;

    printf("Enter the number:\n");
    scanf("%d", &n);

    a = factorial(n);
    printf("The factorial of %d is %d\n", n, a);
}

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n*factorial(n - 1);
    }
    
}