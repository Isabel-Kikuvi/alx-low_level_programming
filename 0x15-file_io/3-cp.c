#include <stdio.h>
#include "main.h"
#include <stdlib.h>

char *create_buf(char *file);
void close_file(int fd);

/**
 * create_buf - allocates bytes for a buffer
 * @file: name of the file
 *
 * Return: pointer to a buffer
 */

char *create_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char *) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
 * close_file - closes a file descriptor
 * @fd: file to be closed
 */

void close_file(int fd)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 0 on sucess
 */

int main(int argc, char *argv[])
{
	char *buf;
	int from, to, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
	if (from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buf);
		exit(98);
	}

	w = write(to, buf, r);
	if (to == -1 || w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buf);
		exit(99);
	}

	r = read(from, buf, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buf);
	close_file(from);
	close_file(to);

	return (0);
}
