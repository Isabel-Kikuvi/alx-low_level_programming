#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end
 *
 * Return: 1 if the file exists and -1 if the file does not exist
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	w = write(o, text_content, len);
	if (w == -1)
	{
		close(o);
		return (-1);
	}

	close(o);
	return (1);
}
