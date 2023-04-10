#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to th standard output
 * @filename: pointer to file
 * @letters: number of letters in function
 *
 * Return: number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buf;

	if (filename == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	if (o == -1)
	{
		return (0);
	}

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(o);
		return (0);
	}

	r = read(o, buf, letters);
	if (r == -1)
	{
		free(buf);
		close(o);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r);
	if (w == -1 || w != r)
	{
		free(buf);
		close(o);
		return (0);
	}
	free(buf);
	close(o);

	return (r);
}
