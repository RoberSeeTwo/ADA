
#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
	{
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 0;
    
    int result;

    printf("\n Fibonacci Series (Recursiva):\n");

    while (1)
	{
        result = fibonacci(n);
        
        printf("\n Fib(%d) = %d \n", n, result);
        n++;
    }

    return 0;
}
