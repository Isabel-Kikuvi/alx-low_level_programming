#include "main.h"
#include <string.h>

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 * consist only of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	char *p = s;

	while (*p && strchr(accept, *p))
	{
		len++;
		p++;
	}
	return (len);
}
