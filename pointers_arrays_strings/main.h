#ifndef MAIN_H
#define MAIN_H

/* 
 * File: main.h
 * Description: Header file that contains prototypes functions.
 * This header ensures that the functions can be used in other files by
 * declaring it here, so other source files can include this header and call it.
 */

/**
 * _putchar - writes the character c to stdout
 */
int _putchar(char c);

/**
 * reset_to_98 - Takes a pointer to an int as parameter and updates the value it points to to 98.
 */
void reset_to_98(int *n);

/**
 * swap_int - swaps the values of two integers.
 */
void swap_int(int *a, int *b);

/**
 * swap_int - returns the length of a string.
 */
int _strlen(char *s);

/**
 * _puts - prints a string, followed by a new line, to stdout.
 */
void _puts(char *str);

#endif

