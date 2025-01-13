#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    long long guess = x / 2;
    while (guess * guess > x)
        guess = (guess + x / guess) / 2;
    return (int)guess;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./a.out <number>");
        return 1;
    }
    int num = atoi(argv[1]);
    if (num < 0)
    {
        printf("provide a non negative number\n");
        return 1;
    }
    int result = mySqrt(num);
    printf("The integer square root of %d is %d\n", num, result);
}
