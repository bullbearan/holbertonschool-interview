#include "palindrome.h"
/**
 * is_palindrome - check the code for
 * @n: head
 * Return: Always 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = n, rev = 0;

	while (tmp > 0)
	{
		rev *= 10;
		rev += tmp % 10;
		tmp /= 10;
	}
	if (n == rev)
		return (1);
	return (0);
}
