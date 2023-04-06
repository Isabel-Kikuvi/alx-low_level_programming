#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to
 *		flip to get from one number to another.
 * @n: first bit to be flipped
 * @m: second bit to be flipped
 *
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int num = 0;

	while (x != 0)
	{
		num += x & 1;
		x >>= 1;
	}
	return (num);
}
