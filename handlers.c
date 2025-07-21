#include "main.h"

/**
 * print_char - Prints a single character
 * @args: Argument list
 *
 * Return: Number of characters printed (1)
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
 *
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
 * print_percent_or_fallback - Handles %% or invalid format
 * @spec: Specifier character
 *
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
