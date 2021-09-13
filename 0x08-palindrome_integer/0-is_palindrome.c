#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
* is_palindrome - check whether or not a given unsigned integer is a palindrome
* @n: number to be checked
* Return: 1 if n is a palindrome, and 0 otherwise
*/

int is_palindrome(unsigned long n)
{
	unsigned long remainder, original;
	unsigned long reversed = 0;

	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
		return (1);
		/* printf("palindrome"); */
	else
		return (0);
		/* printf("not palindrome"); */
}
