#include <stdio.h>

/**
 * add - sums two ints
 * @a: first int
 * @b: second int
 * Return: sum
 */
int add(int a, int b)
{
	return (a + b);
}
/**
 * sub - gives diff of two ints
 * @a: first int
 * @b: second int
 * Return: difference
 */
int sub(int a, int b)
{
	return (a - b);
}
/**
 * mul - multiplies two ints
 * @a: first int
 * @b: second int
 * Return: product
 */
int mul(int a, int b)
{
	return a * b;
}
/**
 * div - divides two ints
 * @a: first int
 * @b: second int
 * Return: quotient
 */
int div(int a, int b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		printf("Error: Division by zero.\n");
		return 0;
	}
}

/**
 * mod - returns the modulo
 * @a: first int
 * @b: second int
 * Return: modulo
 */
int mod(int a, int b)
{
	if (b != 0)
	{
		return (a % b);
	}
	else
	{
		printf("Error: Division by zero.\n");
		return (0);
	}
}
