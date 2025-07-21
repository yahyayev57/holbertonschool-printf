#include "main.h"

/**
 * print_char - Prints a character
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_percent_or_fallback - Prints % or unknown specifier
 * @spec: Specifier character
 * Return: Number of characters printed
 */
int print_percent_or_fallback(char spec)
{
	if (spec == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	write(1, "%", 1);
	write(1, &spec, 1);
	return (2);
}

/**
 * print_int - Prints a signed integer
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	char buffer[12];
	int i = 0;
	unsigned int n;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		n = -num;
	}
	else
	{
		n = num;
	}

	if (n == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}
