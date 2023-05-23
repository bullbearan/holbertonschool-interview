#include "holberton.h"
/**
 * _itoa - to str
 * @i: value
 * @b: value
 * Return: value
 */
char* _itoa(int i, char b[])
	{
	char const digit[] = "0123456789";
	char* p = b;

	if (i < 0)
	{
		*p++ = '-';
		i *= -1;
	}
	int shifter = i;
	do
	{
		++p;
		shifter = shifter / 10;
	}
	while (shifter);
	*p = '\0';
	do
	{
		*--p = digit[i % 10];
		i = i / 10;
	}
	while (i);
	return (b);
}
/**
 * _atoi - check
 * @str: value
 * Return: value
 */
int _atoi(const char* str)
{
	int sign = 1, base = 0, i = 0;

	while (str[i] == ' ')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		base = 10 * base + (str[i++] - '0');
	}
	return (base * sign);
}
/**
 * check_number - check
 * @string: value
 * Return: value
 */
int check_number(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < '0' || string[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * _print - print
 * @string: value
 */
void _print(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
		_putchar(string[i]);
	_putchar('\n');
}
/**
 * main - return
 * @argc: value
 * @argv: value
 * Return: value
 */
int main(int argc, char **argv)
{
	int a, b, res;
	char buffer[1000000];
	char *ress;
	

	if (argc != 3 || !check_number(argv[1]) || !check_number(argv[2]))
	{
		_print("Error");
		exit(98);
	}
	a = _atoi(argv[1]);
	b = _atoi(argv[2]);
	res = a * b;
	ress = _itoa(res, buffer);
	_print(ress);
	return (0);
}
