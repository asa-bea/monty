#include "monty.h"

/**
 * get_file - gets the stream for reading from  file.
 * @fileName: Name of the file to open and set as the stream.
 */

void get_file(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		get_file_failed(fileName);

	arguments->file = fdopen(fd, "r");
	if (arguments->file == NULL)
	{
		close(fd);
		get_file_failed(fileName);
	}
}

/**
 * get_file_failed - handles the error when reading a file fails.
 * @filename: the name of the file that failed to open.
 */

void get_file_failed(char *filename)
{
	dprintf(2, "error: can't open file %s\n", filename);
	free_arguments();
	exit(exit_failure);
}
