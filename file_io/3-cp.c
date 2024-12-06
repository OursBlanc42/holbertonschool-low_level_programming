#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - copies the content of a file to another file
 * Description : This program is an ersatz of the 'cp' command
 * - If the number of arguments is incorrect : exit with code 97
 * - If file_to already exists : will be truncate.
 * - If file_from not exist or cannot be read : exit with code 98
 * - If file_to cant be created or writing to it fail : exit with code 99
 * - If a file descriptor cannot be closed, exit with code 100
 * @filename: test file to read
 * Return: always 0
 */
int main(int argc, char **argv)
{
	/* declare variables */
	char *file_from = NULL;
	char *file_to = NULL;
	int file_desc_from = 0;
	int file_desc_to = 0;
	ssize_t buffer_size = 1024;
	ssize_t nb_byte_read = 0;
	ssize_t nb_print_char = 0;
	char *text_buffer = NULL;

	(void)nb_print_char;

	/* Check the number of argument */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Gets the names of the two files and initializes them in variables */
	file_from = argv[1];
	file_to = argv[2];

	/* try to open the source file */
	file_desc_from = open(file_from, O_RDONLY);
	if ((file_desc_from == -1) || (file_from == NULL))
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", file_from);
		exit(98);
	}

	/* try to open/create the destination file */
	/* the open function will create the file if file doesnt exist */
	/* O_TRUNC will wipe the data if the file exist  */
	file_desc_to = open(file_to, O_CREAT | O_RDWR | O_TRUNC, 0664);

	if (file_desc_to == -1)
	{
		dprintf(STDERR_FILENO, "Can't read from file %s\n", file_to);
		exit(99);
	}

	/* allocate memory for buffer */
	text_buffer = malloc(buffer_size * sizeof(char));

	/* if error closes documents and free memory */
	if (text_buffer == NULL)
	{
		close(file_desc_from);
		close(file_desc_to);
		free(text_buffer);
		return (0);
	}

/**
* Read the file in chunks of 1024 bytes (buffer size)
* The file offset automatically advances after each read
* Repeat the process until the number of bytes read is less
* than the buffer size
*/

	/* initialize nb_byte_read to 1024 to start the first loop */
	nb_byte_read = 1024;
	while (nb_byte_read >= buffer_size)
	{
		nb_byte_read = read(file_desc_from, text_buffer, buffer_size);
		nb_print_char = write(file_desc_to, text_buffer, nb_byte_read);
	}


	close(file_desc_from);
	close(file_desc_to);
	free(text_buffer);

	return (0);
}
