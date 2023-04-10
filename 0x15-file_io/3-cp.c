#include <stdio.h>
#include "main.h"
#include <stdlib.h>

#define BUFFER_SIZE 1024
/*
 * main - copies the content of a file to another file.
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 0 on sucess
 */

int main(int argc, char *argv[])
{
	char *file_from, *file_to;
	int o_from, o_to;
	ssize_t r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	o_from = open(file_from, O_RDONLY);
	if (0_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	o_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (o_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	char buf[BUFFER_SIZE];

	while ((r = read(file_from, buf, BUFFER_SIZE)) > 0)
	{
		w = write(file_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Write to %s failed\n", file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Read from file %s failed\n", file_from);
		exit(98);
	}
	if (close(o_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	if (close(o_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
