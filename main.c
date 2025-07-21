#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("Hello %s!\n", "World");
	len2 = printf("Hello %s!\n", "World");

	_printf("Length: %d, Standard: %d\n", len1, len2);

	_printf("Char: %c, Percent: %%\n", 'A');
	_printf(NULL); /* should return -1 */

	return (0);
}
