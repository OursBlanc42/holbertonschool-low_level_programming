#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"


/**
 * main - check the code
 *
 * Return: Always 0.
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

	/* Check the number of argument */
    if (argc != 3)
    {
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

	/* Gets the names of the two files and initializes them in variables */
	file_from = argv[1];
	file_to = argv[2];

	printf("file_from = %s\n", file_from);
	printf("file_to = %s\n", file_to);

	/* check special case (if filename is NULL return 0) */
	if (file_from == NULL)
	{
		printf("Source file is null\n");
		return (0);
	}

	/* try to open the source file (if the file can not be opened, return 0) */
	file_desc_from = open(file_from, O_RDONLY);
	if (file_desc_from == -1)
	{
		printf("Source file descriptor = -1 : ERROR \n");
		return (0);
	}

	/* try to open/create the destination file */
	/* the open function will create the file if file doesnt exist */
	/* O_TRUNC will wipe the data if the file exist  */
	file_desc_to = open(file_to, O_CREAT | O_RDWR | O_TRUNC, 0664);

	if (file_desc_to == -1)
	{
		printf("Destination file descriptor = -1 : ERROR \n");
		return (0);
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
	
	/* try to read the file*/
	nb_byte_read = read(file_desc_from, text_buffer, 12);
	nb_print_char = write(file_desc_to, text_buffer, 12);

	printf("TEXT = %s\n",text_buffer),

	nb_byte_read = read(file_desc_from, text_buffer, 12);
	nb_print_char = write(file_desc_to, text_buffer, 12);

	printf("TEXT = %s\n",text_buffer),

	printf("nb_byte_read = %lu \n",nb_byte_read);
	printf("nb_print_char = %lu \n",nb_print_char);



	close(file_desc_from);
	close(file_desc_to);
	free(text_buffer);

	return (0);
}