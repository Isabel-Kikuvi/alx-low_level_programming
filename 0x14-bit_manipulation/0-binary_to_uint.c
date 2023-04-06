#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string
 *
 * Return: converted number or 0 if b is null or more
 *	than on char is not 0 0r 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int a = 0;
	int j = 0;

	if (b == NULL)
		return (0);

	for (j = 0; b[j] != '\0'; j++)
	{
		if (b[j] == '0')
		{
			a <<= 1;
		}
		else if (b[j] == '1')
		{
			a <<= 1;
			a |= 1;
		}
		else
			return (0);
	}
	return (a);
}
