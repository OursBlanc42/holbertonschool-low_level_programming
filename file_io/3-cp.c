#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void close_properly(int fd_from, int fd_to, char *text_buffer, ssize_t nb_byte_read, ssize_t nb_print_char)
{
	/*  Check reading errors */
	if (nb_byte_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
	}

	/* Check writing error */
	if (nb_print_char == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file\n");
	}

	/* Try to close destination file */
	if (fd_to >= 0 && close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		if (text_buffer != NULL)
			free(text_buffer);
		exit(100);
	}

	/* Try to close source file*/
	if (fd_from >= 0 && close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		if (text_buffer != NULL)
			free(text_buffer);
		exit(100);
	}

	/* Free memory if allocated */
	if (text_buffer != NULL)
	{
		free(text_buffer);
	}

	/* Error output according to error founded */
	if (nb_byte_read == -1)
		exit(98); /* Erreur de lecture */
	if (nb_print_char == -1)
		exit(99); /* Erreur d'écriture */
}


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
	char *text_buffer = NULL;
	int file_desc_from = -1, file_desc_to = -1;
	ssize_t buffer_size = 1024, nb_byte_read = 0, nb_print_char = 0;

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
	if (file_desc_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98); 
	}

/* Try to open/create the destination file and allocate memory for buffer */

	file_desc_to = open(file_to, O_CREAT | O_RDWR | O_TRUNC, 0664);
	text_buffer = malloc(buffer_size * sizeof(char));

	if ((file_desc_to == -1) || (text_buffer == NULL))
	{
		close_properly(file_desc_from, file_desc_to, text_buffer, nb_byte_read, nb_print_char);
	}

/**
* Read the file in chunks of 1024 bytes (buffer size)
* The file offset automatically advances after each read
* Repeat the process until the number of bytes read is less
* than the buffer size
*/
	/* initialize nb_byte_read to 1 to launch the first loop */
	nb_byte_read = 1;
	while (nb_byte_read > 0)
	{
		nb_byte_read = read(file_desc_from, text_buffer, buffer_size);

		/* error check */
		if (nb_byte_read == -1)
		{
			close_properly(file_desc_from, file_desc_to, text_buffer, nb_byte_read, nb_print_char);
		}

		if (nb_byte_read > 0) /* avoid writing nothing */
		{
			nb_print_char = write(file_desc_to, text_buffer, nb_byte_read);

			/* error check */
			if ((nb_print_char == -1) || (nb_print_char != nb_byte_read))
			{
				close_properly(file_desc_from, file_desc_to, text_buffer, nb_byte_read, nb_print_char);
			}
		}
	}

	/* close each document */
	close_properly(file_desc_from, file_desc_to, text_buffer, nb_byte_read, nb_print_char);

	return (0);
}
