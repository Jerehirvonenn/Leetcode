#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x)
{
    // Negative numbers and numbers ending with 0 cannot be palindromes 
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reverse = 0;
    int original = x;

    while (x > 0)
    {
        int digit = x % 10;
        if (reverse > (INT_MAX - digit) / 10)
            return false; // Overflow, cannot be palindrome
        reverse = reverse * 10 + digit;
        x /= 10;
    }
    return original == reverse;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);
}
